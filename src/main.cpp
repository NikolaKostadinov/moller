#include "../include/moller.hpp"
#include "../include/read.hpp"

#include "TApplication.h"
#include "TCanvas.h"
#include "TRootCanvas.h"
#include "TGraphErrors.h"
#include "TError.h"

#define N               100u                                // number of samples
#define P               6.0d                                // particle CM momentum
#define MASS            0.5d                                // particle invariant mass
#define COUPLING        0.30282212d                         // coupling constant
#define LIMIT           LIMIT_RELATIVISTIC                  // limit of calculation
#define CANVAS_W        720u                                // width of canvas
#define CANVAS_H        720u                                // height of canvas
#define CANVAS_TITLE    "Moller Scattering"                 // title of canvas
#define GRAPH_TITLE     "Differential cross section"        // title of graph
#define MOLLER_TEX_PATH "./tex/moller.tex"                  // path to `.tex` file

int main(int argc, char** argv)
{
    double start    = 0.0;
    double end      = 2*M_PI;

    double* to_theta = new double[N];

    for (unsigned int i = 0; i < N; i++)                    // define theta (angle) samples
        *(to_theta + i) = start + i*(end - start)/(N - 1);  // theta(n+1) = theta(n) + delta_theta
    
    Moller scattering = Moller(N, P, MASS, COUPLING, LIMIT);
    scattering.generateFile(to_theta);

    std::cout << "DATA FILE GENERATED\n";
    
    double* to_x = new double [N];                          // `to_x` matches with `to_theta` but redefined for convenience
    double* to_y = new double [N];                          // differential cross section
    double* to_e = new double [N];                          // relative error of `*to_y`

    importDataFromTo(                                       // helper function
        MOLLER_PATH,                                        // from "../include/read.hpp"
        to_x,                                               // 
        to_y,                                               // it imports the data from the `.dat` file
        to_e                                                // to the pointers
    );                                                      // 

    for (unsigned int i = 0; i < N; i++)                    // convert to absolute error:
        *(to_e + i) *= *(to_y + i);                         // abs_err = rel_err * val

    gErrorIgnoreLevel = kWarning;                           // block ROOT messages

    TApplication* app    = new TApplication("app", &argc, argv);
    TCanvas*      canvas = new TCanvas("canvas", CANVAS_TITLE, CANVAS_W, CANVAS_H);
    TGraphErrors* graph  = new TGraphErrors(N, to_x, to_y, NULL, to_e);
    
    std::cout << "DATA IMPORTED\n";

    graph ->SetTitle(GRAPH_TITLE);
    graph ->SetMarkerStyle(21);
    graph ->SetMarkerColor(4);
    graph ->Draw("ALP");
    canvas->Modified();
    canvas->Update();

    std::cout << "CANVAS UPDATED\n";

    gPad->Print(MOLLER_TEX_PATH);                           // generate `.tex` file

    std::cout << "TEX FILE GENERATED\n";

    TRootCanvas *root = (TRootCanvas*) canvas->GetCanvasImp();

    std::cout << "CONNECTING\n";

    root->Connect(
        "CloseWindow()",
        "TApplication",
        gApplication,
        "Terminate()"
    );

    std::cout << "RUNNING\n";

    app ->Run();

    return 0;
}