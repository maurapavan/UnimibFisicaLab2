/*
c++ -o main_02 `root-config --glibs --cflags` algebra_2.cc main_02.cpp
*/

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

#include "TH1F.h"
#include "TCanvas.h"

#include "algebra_2.h"
#include "generazione.h"

// retta con termine noto non nullo
double g (double x)
  {
     return 3.14 + 2 * x ;
  }


using namespace std ;


// ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----


int main (int argc, char ** argv)
  {
    if (argc < 4)
      {
        cout << "usage: " << argv[0] << " sigma_y N_points Ntoys" << endl ;
        exit (1) ;
      }

    double sigma  = atof (argv[1]) ;
    int N_points  = atoi (argv[2]) ;
    int N_toys    = atoi (argv[3]) ;

    // istogrammi per il disegno dei risultati del fit
    TH1F h_a ("h_a", "termine noto", 
              100, 3.14 * (1. - 1. * sigma), 3.14 * (1. + 1. * sigma) ) ;
    TH1F h_b ("h_b", "coefficiente angolare", 
              100, 2. * (1. - 1. * sigma), 2. * (1. + 1. * sigma) ) ;

    // istogrammi per il disegno dei risultati del fit
    TH1F h_sa ("h_sa", "sigma termine noto", 
              100, 0., 3.14 * 2. * sigma) ;
    TH1F h_sb ("h_sb", "sigma coefficiente angolare", 
              100, 0., 2. * 2. * sigma) ;

    // contatori per la determinazione dell'intervallo di copertura
    int cont_a = 0 ;
    int cont_b = 0 ;

    // generazione dei toy experiment e calcolo del fit per ciascuno di essi
    // ----------------------------------------

    //loop over toys
    for (int i_toy = 0 ; i_toy < N_toys ; ++i_toy)
      {
        vector<double> asse_x ;
        vector<double> asse_y ;

        // generare il sample
        // --------------------

        for (int i_point = 0 ; i_point < N_points ; ++i_point)
          {
            double epsilon = rand_TAC_gaus (sigma) ; 
            asse_x.push_back (i_point) ;
            asse_y.push_back (g (i_point) + epsilon) ;
          }

        // trovare i parametri
        // --------------------

        matrice H (N_points, 2) ;
        for (int i = 0 ; i < N_points ; ++i)
          {
            H.setCoord (i, 0, 1) ;
            H.setCoord (i, 1, asse_x.at (i)) ;
          }
        vettore y (asse_y) ;
        matrice V (N_points) ;
        for (int i = 0 ; i < N_points ; ++i) V.setCoord (i, i, sigma * sigma) ;
    
        matrice V_inv = V.inversa () ;
        matrice theta_v = (H.trasposta () * V_inv * H).inversa () ;
        vettore theta = (theta_v * (H.trasposta () * V_inv)) * y ;

        h_a.Fill (theta.at (0)) ;
        h_b.Fill (theta.at (1)) ;

        h_sa.Fill (sqrt (theta_v.at (0,0))) ;
        h_sb.Fill (sqrt (theta_v.at (1,1))) ;

        if (fabs (theta.at (0) - 3.14) < sqrt (theta_v.at (0,0))) ++cont_a ;
        if (fabs (theta.at (1) - 2.  ) < sqrt (theta_v.at (1,1))) ++cont_b ;

      } //loop over toys

    cout << "copertura parametro a: " << static_cast<double> (cont_a) / N_toys << endl ;
    cout << "copertura parametro b: " << static_cast<double> (cont_b) / N_toys << endl ;

    TCanvas c1 ;
    h_a.Draw ("hist") ;
    c1.Print ("parametro_a.png", "png") ;
 
    h_b.Draw ("hist") ;
    c1.Print ("parametro_b.png", "png") ;

    h_sa.Draw ("hist") ;
    c1.Print ("parametro_a_var.png", "png") ;
 
    h_sb.Draw ("hist") ;
    c1.Print ("parametro_b_var.png", "png") ;
    return 0 ;
  }
