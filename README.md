#CEAL implementation examples

This repository contains a CEAL Windows executable and some demonstration tests.

Please note, the executable is built with a slow numerical library
(for compatibility purposes). The timing results are
expected to be slightly different from those presented in the paper.

Files:
* usage.pdf - extract from the CEAL technical document (to be released separately)
* ceal.exe - Windows executable, Win7 or higher version is required
* tests.zip - selected test cases

How to run the PIR example:
-   Unpack tests.zip
-   Go to "pir" directory
-   Run the example
  - pathto\ceal.exe 204.sca
-   Observe output
  -   38181.39206 45559.25955 14829.32282 8946.21379 
  -   18846.3887 13765.29333 13765.29333 8
        * The first 6 outputs are intermediate sum values
        * The second to the last number is the encrypted result.
        * The last number (8) is the decrypted value printed 
          from inside the program by the ".outd" macro.

December 2015
