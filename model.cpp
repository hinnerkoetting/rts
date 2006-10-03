/////////////////////////////////////////////////////////////////
//
//					model.cpp
//					load 3ds file
//
//					
//
/////////////////////////////////////////////////////////////////



#include "errors.h"

#include <iostream>
#include <tchar.h>
#include "gl/glut.h"
// Include the library
#include "ease\EaseInclude\EaseWrapperD3DGL\Core\Standard.h"
#include "ease\EaseInclude\EaseImport\EaseImport.h"
using namespace EaseWrapper;
using namespace EaseImport;


// Ease libraries
#pragma comment (lib, "ease\\EaseLib\\EaseCore.lib")
#pragma comment (lib, "ease\\EaseLib\\EaseWrapperD3DGL.lib")
#pragma comment (lib, "ease\\EaseLib\\EasePCB.lib")
#pragma comment (lib, "ease\\EaseLib\\EaseImport.lib")

#include "model.h"
#include "exit.h"
Model::Model(char* filename) {
	// Create a light
	InitWrapperStruct	initStr;
	initStr._api			= EASE_OPENGL;							// The API you choose to render : EASE_OPENGL or EASE_DIRECTX
	initStr._width			= 400;									// Width  of the window
	initStr._height			= 300;									// Height of the window
	initStr._fsaa			= false;								// Fullscreen antialiasing flag
	initStr._fullscreen		= false;								// Fullscreen window flag
	initStr._windowBorder	= true;	 								// The window will have a border
	initStr._windowName		= "Tutorial 13 : Importing PCB file with EaseWrapper";
	initStr._maxBufferSize	= 100000;								// Maximum buffer size (vertex buffer)
 
	// Send these parameters to the library
	InitWrapperD3DGL(initStr);	

	
		vertexArray = new CVertexArray();							// The vertex array
	faceIndices	= 0;							// The face indices
			
	texture		= 0;							// Texture
	light		= 0;							// Light
	material	= 0;							// Material
ImportPCB(filename);
	light	= new CLightBasic();									// Create the light
	light->SetType(LIGHT_DIREC);									// Set the light type : Directional light
	light->SetDirection(CVector3(0.0f,0.0f,-1.0f));					// Set the light-ray direction
	light->SetAmbient (0.2f,0.2f,0.2f,1.0f);						// Set the ambient  color (black)
	light->SetDiffuse (0.8f,0.8f,0.8f,1.0f);						// Set the diffuse  color (green)
	light->SetSpecular(0.0f,0.0f,0.0f,1.0f);						// Set the specular color (black)

	// Create a material
	material = new CMaterialBasic();								// Create the material
	material->SetAmbient (1.0f,1.0f,1.0f,1.0f);						// Set the ambient  color
	material->SetDiffuse (1.0f,1.0f,1.0f,1.0f);						// Set the diffuse  color
	material->SetSpecular(1.0f,1.0f,1.0f,1.0f);						// Set the specular color
	material->SetEmission(0.0f,0.0f,0.0f,1.0f);						// Set the emissive color
	material->SetShininess(7.0f);									// Set the shininess*/
	//if(!ImportPCB(filename)) {
	//	int a = 1;
//		Error::MesBoxOk(("Kann Datei %s nicht oeffnen", filename), "error");
	//	Exit::doIt();
	//}
	light	= new CLightBasic();									// Create the light
	light->SetType(LIGHT_DIREC);									// Set the light type : Directional light
	light->SetDirection(CVector3(0.0f,0.0f,-1.0f));					// Set the light-ray direction
	light->SetAmbient (0.2f,0.2f,0.2f,1.0f);						// Set the ambient  color (black)
	light->SetDiffuse (0.8f,0.8f,0.8f,1.0f);						// Set the diffuse  color (green)
	light->SetSpecular(0.0f,0.0f,0.0f,1.0f);						// Set the specular color (black)

	// Create a material
	material = new CMaterialBasic();								// Create the material
	material->SetAmbient (1.0f,1.0f,1.0f,1.0f);						// Set the ambient  color
	material->SetDiffuse (1.0f,1.0f,1.0f,1.0f);						// Set the diffuse  color
	material->SetSpecular(1.0f,1.0f,1.0f,1.0f);						// Set the specular color
	material->SetEmission(0.0f,0.0f,0.0f,1.0f);						// Set the emissive color
	material->SetShininess(7.0f);									// Set the shininess
}	




///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		NewTexture
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Model::NewTexture(PCBTexture* srceTexture)
{
	// Gets the source-texture data
	int		w = srceTexture->_width;								// Width  of the texture
	int		h = srceTexture->_height;								// Height of the texture
	ubyte*	bmp = srceTexture->_bitmapRGBA;							// The bitmap buffer of the texture

	// Create the EaseWrapper texture
	texture = new CTextureBasic();									// Create the texture
	texture->LoadBuffer2D(bmp, w, h, TEXTUREFILTER_BILINEAR);		// Load the bitmap
	texture->SetWrapU(TEXWRAP_WRAP);								// Set U-wrap mode to 'repeat'
	texture->SetWrapV(TEXWRAP_WRAP);								// Set V-wrap mode to 'repeat'

	return true;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		NewTopology
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool Model::NewTopology(PCBTopo* srctopo)
{
	// Create the geometry ressources
	vertexArray = new CVertexArray();								// Create the vertex array
	faceIndices = new CIndexBuffer();								// Create the face indices

	// White color
	CVector4	white(1.0f,1.0f,1.0f,1.0f);

	// Add vertices and faces
	for(int i=0; i<srctopo->_NbFaces; i++)
	{
        PCBFace*	srcFace = srctopo->_Faces[i];					// Get a pointer on the current face

		CVector3	vertexPos[3];									// Here are stored the vertex positions
		int*		ref = srcFace->_vertexRef;						// Get the vertex references
		vertexPos[0] = srctopo->_Vertex[ref[0]] * 0.02f;			// Get the position for vertex 0, and scale it to fit in the screen
		vertexPos[1] = srctopo->_Vertex[ref[1]] * 0.02f;			// Get the position for vertex 1, and scale it to fit in the screen
		vertexPos[2] = srctopo->_Vertex[ref[2]] * 0.02f;			// Get the position for vertex 2, and scale it to fit in the screen

		CUV			texCoord[3];									// Here are stored the texture coordinates
		int			channel = 0;									// We use only the first channel in this example (single texture)
		texCoord[0] = srcFace->_UV[0][channel];						// Get the texture coordinates for vertex 0
		texCoord[1] = srcFace->_UV[1][channel];						// Get the texture coordinates for vertex 1
		texCoord[2] = srcFace->_UV[2][channel];						// Get the texture coordinates for vertex 2

		vertexArray->AddCompleteVertex(vertexPos[0], srcFace->_normalVert[0], white, texCoord[0], CUV(), CUV(), CUV());
		vertexArray->AddCompleteVertex(vertexPos[1], srcFace->_normalVert[1], white, texCoord[1], CUV(), CUV(), CUV());
		vertexArray->AddCompleteVertex(vertexPos[2], srcFace->_normalVert[2], white, texCoord[2], CUV(), CUV(), CUV());

		faceIndices->AddIndex(i*3+0);								// Add the vertex index for this new face
		faceIndices->AddIndex(i*3+1);								// Add the vertex index for this new face
		faceIndices->AddIndex(i*3+2);								// Add the vertex index for this new face
	}

	vertexArray->Flush();											// Copy all these vertices to the render library (should do that each time you add or modify vertices)

	return true;
}

void Model::draw() {
// Set the viewport
	//int	width, height;												// Window width and height
	//window->GetSize(&width, &height);								// Get the window size, which could have changed
	//RSManager->SetViewPort(0,0,width,height);						// Reset The Current Viewport

	// Clear the screen and ZBuffer
	//CVector4	color(0.5f, 0.5f, 0.5f, 1.0f);						// ClearColor
	//RSManager->ClearScreen(true, true, color, 1.0f);				// Clear screen and Zbuffer

	// Set the view matrix
	//RSManager->SetViewMatrix(IdentityMatrix());						// Set the view matrix to identity

	// Set the projection matrix
	//CMatrix4	projMatrix;											// Create the projection matrix
	//projMatrix.PerpectiveMatrix(45.0f, (float)width/(float)height, 0.1f, 100.0f);
	//RSManager->SetProjMatrix(projMatrix);							// Set the projection matrix

	// Apply the light and the material for the faces
	//RSManager->SetLight(0, light);									// Set light parameters as the first light (number zero)
	//RSManager->SetMaterialProperties(material);						// Set material parameters

	// Apply the texture
	//RSManager->SetTextureBitmap(0, texture);						// Set the texture on the first texture-stage (number zero)

	// Set the model matrix
	//CMatrix4	modelMatrix;										// Create the model matrix (Identity by default)

	//RSManager->SetWorldMatrix(modelMatrix);							// Set the world matrix
	// Draw the polygons
	//RSManager->BeginScene();										// Begin the rendering stage
	glBegin(GL_TRIANGLES);
	faceIndices->RenderIndices(vertexArray, DRAW_TRIANGLES);		// Draw the faces
	glEnd();	
}