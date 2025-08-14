# GetVectorTuple
Transform files from Clas12-rge-analysis format to Clas6 format (vectorial tuples as obtained with [GetSimpleTuple](https://github.com/utfsm-eg2-data-analysis/GetSimpleTuple/tree/csanmart/analysis-pion-phipq)) for compatibility with old analyses.

Files created using the [Clas12-rge-analysis repo](https://github.com/antorad/clas12-rge-analysis/tree/development) are expected to be saved in a directory called `/clas12_data`.

This program currently supports data files only (i.e. no *generation-level branches* included).
Although the implementaton might be direct, it is still a **work in progress**.

## Running the program
Follow the instructions:
```
make
./bin/GetVectorTuple -r <number>
```
- Running `make` will create the executable **GetVectorTuple** and two directories: `/bin` (where the executable will be located) and `/output` (where the new-formatted tuples will be saved).
- The option `-r` requires the run number of the file (`<number>`), saved in `/clas12_data` following the format: `ntuples_dc_<number>.root`.
*Example*: To get the vector tuples from the file `./clas12_data/ntuples_dc_020082.root`, do `./bin/GetVectorTuple -r 020082`.
- When changes are made and you are re-compiling, remember to use `make clean` before `make`, just in case.
