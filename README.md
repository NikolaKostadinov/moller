# Testing ROOT with Møller Scattering

This is a small `C++` project with the aim of testing CERN's `ROOT`. It is composed of a program that generates a `ROOT` plot of the differential cross section of QED electron-electron interaction (Møller scattering), a `.dat` file with the generated data and a `.tex` file of the plot. The `.tex` plot could be compiled to a `.pdf` with a defined $\LaTeX$ template.

$$ e^- + e^- \rightarrow e^- + e^- $$

## Requirements

* `Linux`
* `make`
* `ROOT`
* `LuaLaTeX`

## Working with `moller-scattering`

To compile the program as an executable use `make` with target `exe`.

```console
$ make exe
```

The program is build in the `./bin` directory. To execute it:

```console
$ bin/main
```

The program generates a `.dat` file in the direcotry `./data`. If you want to change that see [*parameters*](##parameters). To compile (make) the $\LaTeX$ document use `make` with target `pdf`. If you don't want an automatic clean-up use target `pdf-dirty`.

```console
$ make pdf
```

> Note: `make pdf` uses `LuaLaTeX`

## Parameters

The program has parameters that could be changed. They are defined in `./src/main.cpp`. The default parameters are given:

```cpp
#define N                   100u                                            // number of samples
#define P                   1.0                                             // electron CM momentum
#define MASS                1.0                                             // electron invariant mass
#define COUPLING            0.30282212                                      // coupling constant
#define LIMIT               LIMIT_RELATIVISTIC                              // limit of calculation
#define EXCLUSION_ARC       0.6                                             // arc of exclusion
#define CANVAS_W            720u                                            // width of canvas
#define CANVAS_H            720u                                            // height of canvas
#define CANVAS_TITLE        "Moller Scattering"                             // title of canvas
#define GRAPH_LABEL         "Differential Cross Section;"           \
                            "\\theta\\,[rad];"                      \
                            "\\frac{d^2\\sigma}{d\\Omega^2}\\,[mb]"         // graph title \ x label \ y label
#define MOLLER_DAT_PATH     "./data/moller.dat"                             // path to `.dat` file
#define MOLLER_TEX_PATH     "./tex/diagrams/moller-cross-section.tex"       // path to `.tex` file
```

> The default value `GRAPH_LABEL` literaly means "Differential Cross Section; $\theta\,[rad]$; $\frac{d^2\sigma}{d\Omega^2}\,[mb]$"

