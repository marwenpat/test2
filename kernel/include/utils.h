#ifndef UTIL
#define UTIL

#include <limits>
#include <tnt.h>

// Mit \addtogroup k�nnen wir in Doxygen Header und andere Dateien
// zusammenfassen und auf einer HTML-Seite dokumentieren.

//! \addtogroup util util - N�tzliches, Konstanten, ...
/*! \addtogroup util
  *  @{
  */
  
//! Konstante f�r die kleinste zul�ssige double-Zahl
const double mPrecision = std::numeric_limits<double>::epsilon();
//! Konstante f�r die �berpr�fung der Genauigkeit der Ergebnisse
const double Eps = 5.0E-12;

//! Funktion f�r die Besetzung des i-ten kanonischen Einheitsvektors im R^n (i beginnt bei 0)
TNT::Vector<double> unitVector(int i, int n);

//! Berechnung der Maximumsnorm eines Vektors
double normMaximum(TNT::Vector<double> v);

//! Vergleich eines TNT Vektors mit einem Zielvektor mit Hilfe der euklidischen Norm
/*!
*  \param value   Erster Vergleichsvektor
*  \param target Zweiter Vergleichsvektor
*  \param epsilon Genauigkeit
*  \return true, falls die euklidische der beiden Vektoren kleiner als die interne Genauigkeit ist.
*/
bool compareVector(TNT::Vector<double> value, TNT::Vector <double> target, double epsilon);

//! Vergleich eines eindimensionalen Arrays mit einem Zielvektor mit Hilfe der Maximums-Norm
/*!
*  \param value   Erster Vergleichsvektor
*  \param target Zweiter Vergleichsvektor
*  \param epsilon Genauigkeit
*  \return true, falls die MaximumsNorm der beiden Vektoren kleiner als die interne Genauigkeit ist.
*/
bool compareVectorMaximumNorm(TNT::Vector<double> value, TNT::Vector<double> target, double epsilon);

 /*! @}  end doxygen addtogroup util */	
#endif // UTIL
