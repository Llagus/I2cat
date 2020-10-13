---

# PROJECT V2X-ARCH, 11p

IEEE 802.11p framework section.


## To build

Several packages are required to build the code with our modifications. Next are the versions known to work.

* **OMNET++**: download and build v5.1.1, edit "configure.user" file for building with g++, no TK, no OSG.
* **SUMO**: download and build v0.29.0
* **ARTERY**: follow instructions in its own README


note: depending on your Linux distribution, you may need additional dependencies such as C++ Boost Dev libs.
note: artery, sumo-0.29 and omnet++ must be at the same folder hierarchy level.



## To modify & run

Use Sublime IDE. Besides C++ source code, we provide...

    1. A path and setup configurator file "source_conf_11p.cmd". Run this first once.
       This sets up PATHs for a short user name "kaz". Just create this user and run
       anything related to v2x-arch under it or adapt the scripts.

    2. Centralized and commented "omnetpp.ini" simulator configuration file.
       Read this as it contains extended execution instructions and explanations.
    
    3. Two building-systems (ctrl+B) for sublime.
       These call respective bash scripts "./run_ARTERY_from*.cmd".
       They basically differ in the "-u" option (that is GUI or CMD environment)

    4. OMNET++ result analysis files.
    
    5. Complete SUMO networks.
    
    6. etc.

---
