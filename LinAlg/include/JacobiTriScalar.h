#ifndef JACOBITRISCALAR_H
#define JACOBITRISCALAR_H

#include <tnt.h>
#include "Iterative.h"
#include "TriDiagScalar.h"

//! Gesamtschritt-Verfahren zur L�sung eines linearen Gleichungssystems
/*!
 * Diese Klasse realisiert die L�sung eines linearen Gleichungssytems
 * mit Hilfe des Gesamtschritt- oder JacobiTriScalar-Verfahrens.
 *
 * Die Koeffizientenmatrix ist eine tridiagonale Matrix mit
 * konstanten Werten auf den Diagonalen, realisiert durch die Klasse
 * TriDiagScalar.
 */
class JacobiTriScalar : public Iterative
{
public:
    
        //! Defaultkonstruktor
	    /*!
	     *  n wird 0 gesetzt.
		 *
		 *  Abbruchgenauigkeit ist Eps aus utils.h
		 *
		 *  Maximale Anzahl der Iterationen ist 0
		 */
	    JacobiTriScalar();

		//! Konstruktor mit den Diagonalelementen
		/*!
		*  Falls ein Diagonalelement zu klein ist gibt es eine
		*  Ausgabe auf std::cerr. Dann sollte die Iteration nicht
		*  durchgef�hrt werden.
		*
		* Abbruchgenauigkeit ist Eps aus utils.h
		*
		*  Maximale Anzahl der Iterationen ist 10
		*
		* \param d Diagonale
		* \param up Obere Nebendiagonale
		* \param low Untere Nebendiagonale
		* \param rhs rechte Seite des Gleichungssystems
		*/
		JacobiTriScalar(double d, double up, double low, TNT::Vector<double> rhs);

        //! Konstruktor mit einer Koeffizientenmatrix
        /*!
		 *  Falls ein Diagonalelement zu klein ist gibt es eine
		 *  Ausgabe auf std::cerr. Dann sollte die Iteration nicht
		 *  durchgef�hrt werden.
		 *
		 * Abbruchgenauigkeit ist Eps aus utils.h
		 *
		 *  Maximale Anzahl der Iterationen ist 10
		 *
         * \param matrix Koeffizientenmatrix
		 * \param rhs rechte Seite des Gleichungssystems
         */
		JacobiTriScalar(TriDiagScalar matrix, TNT::Vector<double> rhs);

		//! Konstruktor mit Koeffizientenmatrix, einer rechten Seite, Abbruchgenauigkeit und maximaler Anzahl der Iterationen
		/*!
		*  Die Diagonallemente werden �berpr�ft. Falls ein Diagonalelement zu klein ist gibt es eine
		*  Ausgabe auf std::cerr. Dann sollte die Iteration nicht
		*  durchgef�hrt werden.
		*
		* \param matrix Koeffizientenmatrix
		* \param rhs rechte Seite des Gleichungssystems
		* \param epsilon Abbruchgenauigkeit
		* \param maxI Maximale Anzahl der Iterationen
		*/
		JacobiTriScalar(TriDiagScalar matrix, TNT::Vector<double> rhs, double epsilon, unsigned int maxI);

		//! Durchf�hren eines Iterationsschritts
		/*!
		* Funktion, in der ein Schritt des Algorithmus durchgef�hrt wird.
		* In dieser Funktion wird das Abbruchkriterium durchgef�hrt
		* und, falls es erf�llt ist, muss die Funktion die Variable
		* Iterative::shouldStop auf true gesetzt werden.
		*
		* \return Aktuelle N�herung wird zur�ckgegeben.
		*/
		virtual void iterate();

        //! Ausgabe der Inhalt der Instanz auf der Konsole
        void print() const;
private:
	    //! Diagonalelement
		double diag;
		//! Oberes Diagonalelement
		double upper;
		//! Unteres Diagonalelement
		double lower;
	    //! Vektor f�r die vorhergehende L�sung in der Iteration
	    TNT::Vector<double> xalt;
};

// - Inline section ---------------------------------------


#endif
