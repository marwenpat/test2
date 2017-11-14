#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H

#include <tnt.h>
#include "Iterative.h"

//! Einzelschritt-Verfahren zur L�sung eines linearen Gleichungssystems
/*!
 * Diese Klasse realisiert die L�sung eines linearen Gleichungssytems
 * mit Hilfe des Einzelschritt- oder Gauss-Seidel-Verfahrens.
 *
 * Es wird davon ausgegangen, dass die Koeffizientenmatrix eine voll
 * besetzte Matrix ist.
 */
class GaussSeidel : public Iterative
{
public:
        //! Defaultkonstruktor
	    /*!
	     *  n wird 0 gesetzt.
		 *  Abbruchgenauigkeit ist Eps aus utils.h
		 *
		 *  Maximale Anzahl der Iterationen ist 0
		 */
	    GaussSeidel();

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
		GaussSeidel(TNT::Matrix<double> matrix, TNT::Vector<double> rhs);

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
		GaussSeidel(TNT::Matrix<double> matrix, TNT::Vector<double> rhs, double epsilon, unsigned int maxI);

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
	//! Zeiger auf eine Instanz einer  Matrix
	TNT::Matrix<double> A;
	//! Vektor f�r die vorhergehende L�sung in der Iteration
	/*!
	 * Dieser Vektor wird ausschlie�lich f�r das Abbruchkriterium ben�tigt!
	 */
	TNT::Vector<double> xalt;
};

#endif
