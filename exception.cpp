#include "exception.h"

////////////////////////////////////////////////////////////////////////////
// Exception handling

// Encapsulate a string
// Construktor.
// message ist ein Meldungstext.
GeneralGameException::GeneralGameException(const std::string& message)
{
	text = new std::string(message);
}

GeneralGameException::GeneralGameException(const GeneralGameException& otherEx)
{
	text = new std::string(*otherEx.text);
}

const GeneralGameException&
GeneralGameException::operator =(const GeneralGameException &otherEx)
{
	if (text)
		delete text;

	text = new std::string(*otherEx.text);

	return *this;
}

// Accessor für die enthaltene Meldung.
std::string GeneralGameException::Text() const {
	return *text;
}

// Destruktor; keine Besonderheiten.
GeneralGameException::~GeneralGameException()
{
	delete text;
}