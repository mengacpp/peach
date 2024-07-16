**To create a new project:**

1. Duplicate this directory and place it wherever we want the new project
2. Rename the folder to the project name
3. Navigate into the project folder and run
   ```bash
   mkdir build
   cd build
   cmake .. -DPROJECT_NAME=<project-name>
   ```
4. Run `make build` whenever the editor request to play the game