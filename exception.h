////////////////////////////////////////////////////////////////////////////
// Ausnahmebehandlung

// Ausnahmeklasse für Ausnahmen im Spiel
// Kapselt nur einen String.
#include <string>
class  GeneralGameException {
public:
	// Konstruktor.
	// message ist ein Meldungstext
	GeneralGameException(const std::string& message);
	// Copykonstruktor
	GeneralGameException(const GeneralGameException& otherEx);

	// Zuweisungsoperator
	const GeneralGameException& operator=(const GeneralGameException& otherEx);

	// Destruktor; keine Besonderheiten.
	~GeneralGameException();

	// Accessor für die enthaltene Meldung.
	std::string Text() const;
protected:
	// Die Meldung selbst.
	std::string* text;
};