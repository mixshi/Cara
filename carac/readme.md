# The CaraVM Bytecode Compiler

Documentation for the CaraVM Bytecode Compiler `CaraC`

__ASOF Nov 17, 2024, The Contents of this File are *Not Yet Implemented.*__

## Usage

File names are as such:\
`program.cmc`

And are ran in the CLI with\
`cara run program.cmc`

CMC files can be compiled from scenes using the CMC Compiler `CaraC`\
`carac --build-scene some_scene.scn`

Linkages must be specified\
`carac --build-scene some_scene.scn --link script.cara`\

Using shorter flags\
`carac -b scene.scn -l script.cara`

Specify outfile\
`carac -b scene.scn -l script.cara -o program.cmc`
