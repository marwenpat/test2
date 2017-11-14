#ifndef VISUTIL
#define VISUTIL

#include <tnt.h>

//! \addtogroup visutil visutil - N�tzliches, Konstanten, ...
/*! \addtogroup visutil
  *  @{
  */
  
//! Ausgabe einer Linie als VTK-Datei
/*!
 * Die VTK-Datei kann mit ParaView oder dem VTK-Framework
 * ge�ffnet und damit eine Visualisierung erstellt werden.
 *
 * Verwenden Sie die ParaView-Pipeline-Datei, die online
 * zur Verf�gung steht. Oder �ffnen Sie im Datei-Dialog
 * in Paraview die mit dieser Funktion erzeugte
 * vtk-Datei und f�gen Sie eine Farbtabelle hinzu.
 *
 * \param fileName Dateiname
 * \param x Vektor mit den x-Koordinaten der Diskretisierung
 * \param y Vektor mit den y-Koordinaten der Diskretisierung
 * \return Fehlercodes
 *
 * 0 = success
 * 1 = Fehler beim �ffnen der Ausgabedatei
 */
short storeLine(string fileName, 
	            TNT::Vector<double> x, 
				TNT::Vector<double> y);

//! Ausgabe einer zweidimensionalen Datenstruktur als VTK-Datei
/*!
* Die VTK-Datei kann mit ParaView oder dem VTK-Framework
* ge�ffnet und damit eine Visualisierung erstellt werden.
*
* Verwenden Sie die ParaView-Pipeline-Datei, die online
* zur Verf�gung steht. Oder �ffnen Sie im Datei-Dialog
* in Paraview die mit dieser Funktion erzeugte
* vtk-Datei und f�gen Sie eine Farbtabelle hinzu.
*
* \param fileName Dateiname
* \param values Matrix mit den Werten an den n*n Punkten, also einschlie�lich
*               der Randwerte! Die Werte werden zeilenweise erwartet. Bei 
*               n=8 werden 8 Zeilen mit jeweils 8 Eintr�gen in die Datei
*               beschrieben.
*               Es m�ssen alle Werte, auch die Randwerte, �bergeben werden.
*               Im station�ren Fall mit 6 Punkten pro Zeile, f�r die die N�herung berechnet wird,
*               wird eine 8x8-Matrix erwartet.
* \return Fehlercodes
*
* 0 = success
* 1 = Fehler beim �ffnen der Ausgabedatei
*/
short storeMatrix(string fileName,
	              TNT::Matrix<double> values);

 /*! @}  end doxygen addtogroup visutil */	
#endif // VISUTIL
