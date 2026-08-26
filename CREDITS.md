# Credits and Acknowledgements

This project would not have been possible without the work of people in the PlayStation 2 online preservation, Resident Evil Outbreak, and game-server reverse-engineering communities.

The purpose of this page is to clearly acknowledge projects, research, implementations, documentation, and prior preservation work that have been used as references during development of the PAL Resident Evil Outbreak File #2 server. Something I should have done sooner, again no ill will.

## openSNAP

**Repository:** [GrenderG/openSNAP](https://github.com/GrenderG/openSNAP)

openSNAP is an open, clean-room implementation of the Sega Network Application Package, or SN@P.

After development of this project had already begun, openSNAP was discovered and became an important reference for understanding SN@P protocol behaviour, packet structures, transport behaviour, and the relationship between the different SN@P services.

openSNAP also demonstrates working support for Auto Modellista and is an important project for the wider goal of preserving games which relied on Sega SN@P infrastructure.

Thank you to GrenderG and everyone else for contributing to openSNAP.

---

## BioServer / BioServer2

**Preservation repository:** [corbin-zip/bioserver](https://github.com/corbin-zip/bioserver) 
**Original:** [gh0stl1ne/Bioserver2](https://gitlab.com/gh0stl1ne/Bioserver2)

The BioServer projects are the existing replacement servers for the Japanese versions of Resident Evil Outbreak and Resident Evil Outbreak File #2.

BioServer has been an extremely valuable reference for understanding the intended Outbreak server-side behaviour, including concepts such as authentication, lobby state, rooms, scenarios, game state, and the overall flow expected by an Outbreak client.

The PAL and NTSC-U versions use Sega SN@P networking and therefore cannot simply use BioServer directly. However, BioServer provides an invaluable behavioural reference for determining what the Western SN@P implementation ultimately needs to reproduce.

Thank you to ghostline, the OBSRV community, the maintainers who preserved the source code, and everyone involved in keeping Resident Evil Outbreak online.

---

## DNAS Replacement Server

**Repository:** [FogNo23/DNASrep](https://github.com/FogNo23/DNASrep)

DNASrep is a replacement implementation of Sony's Dynamic Network Authentication System used by PlayStation 2 online games.

The project uses captured authentication data from the DNAS Forever preservation effort and provides the server-side components necessary to reproduce DNAS authentication for supported PlayStation 2 games.

---

## Outbreak Server Resurrection

**Community:** [OBSRV](https://obsrv.org/)

The Outbreak Server Resurrection community has spent many years preserving the online functionality of Resident Evil Outbreak and Resident Evil Outbreak File #2.

Their research, documentation, testing, server development, packet captures, and preservation work established much of the foundation that makes projects such as this possible.

This project is not intended to replace or diminish that work. The goal is specifically to investigate and restore the original Western PAL/NTSC SN@P implementation and make it possible for an original, unmodified Western PlayStation 2 client to function as it did when the official servers were available.
