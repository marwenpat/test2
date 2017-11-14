#ifndef TRIDIAGSCALAR_H
#define TRIDIAGSCALAR_H

#include "TriDiagArray.h"

//! Repr�sentation einer tridiagonalen Matrix, die in jeder Diagonalen konstante Werte enth�lt
/*!
 * Nicht nur bei der Diskretisierung von partiellen Differzialgleichungen
 * mit finiten Differenzen treten tridiagonale Matrizen auf, deren Diagonalelemente
 * konstant sind. Diese Klasse ist von der Basisklasse TriDiagArray
 * abgeleitet. 
 */
class TriDiagScalar : public TriDiagArray
{
public:
    
        //! Defaultkonstruktor
	    /*!
	     *  n wird 0 gesetzt, die Felder f�r die Koeffizientenmatrix
	     *  ebenfalls!
	     */
	    TriDiagScalar();

        //! Konstruktor f�r eine Matrix mit konstanten Diagonal-Elementen
        /*!
         * \param lda Anzahl Zeilen und Spalten
         * \param a Der konstante Wert f�r die Diagonale
	     * \param b Der konstante Wert f�r die obere Nebendiagonale
	     * \param c Der konstante Wert f�r die untere Nebendiagonale
         */
		TriDiagScalar(int lda, double a, double b, double c);

        //! Multiplizieren der Matrix mit einem �bergebenen Vektor
        /*!
         * \param x Der Vektor f�r den A*x berechnet wird.
	     * \return Zeiger auf ein Feld der L�nge lda mit dem Ergebnis der Multiplikation A*x
         */
		virtual TNT::Vector<double> ATimesX(TNT::Vector<double> x) const;

        //! Ausgabe der Inhalt der Instanz auf der Konsole
        virtual void print() const;

		//! Abfragen der Diagonale
		/*!
		 * \return Ein Feld der L�nge 1 mit dem konstanten Wert auf der Hauptdiagonale
		 */
		virtual TNT::Vector<double> getDiagonal() const;

		//! Abfragen der Elemente der unteren Nebendiagonale der Matrix
		/*!
		 * \return Ein Feld der L�nge 1 mit dem konstanten Wert auf der oberen Nebendiagonale
		 */
		virtual TNT::Vector<double> getUpperDiagonal() const;

		//! Abfragen des i-ten Elements der unteren Nebendiagonale
		/*!
		 * \return Ein Feld der L�nge 1 mit dem konstanten Wert auf der unteren Nebendiagonale
		 */
		virtual TNT::Vector<double> getLowerDiagonal() const;

		//! Abfragen des Werts auf der Diagonalen
		virtual double getDiagonalElement() const;

		//! Abfragen des Werts auf der oberen Nebendiagonalen
		virtual double getUpperElement() const;

		//! Abfragen des Werts auf der unteren Nebendiagonalen
		virtual double getLowerElement() const;

private:
        //! Konstanter Wert auf der Hauptdiagonale
	    double diagValue;
		//! Konstanter Wert auf der oberen Nebendiagonale
		double upperValue;
        //! Konstanter Wert auf der unteren Nebendiagonale
		double lowerValue;
};

// - Inline section ---------------------------------------

inline double TriDiagScalar::getDiagonalElement() const { return diagValue; }

inline double TriDiagScalar::getUpperElement() const { return upperValue; }

inline double TriDiagScalar::getLowerElement() const { return lowerValue; }
#endif
