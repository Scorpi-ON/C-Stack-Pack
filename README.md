# Stack Pack — deal with dynamic structuers easily!
This toolkit was created during the preparation for the programming exam. To speed up the solution of tasks from several exam tickets, I desided to separate the common I/O and stack functions from the unique ones for each specific task.

**It will be useful for you if you want to:**
- better understand dynamic structures and recursion 
- improve C skills — the package covers topics such as pointers, files, preprocessor etc.
- solve another ticket or lab work — focus on your task, the rest of code is already written!

### Works in
- [x] Windows *(Visual Studio IDE)*
- [x] Linux *(Clang compiler)*
- [ ] Mac *(not tested)*

### Structure
- **lib** — 
    - **stack.c** — 
    - **stack.h** —
    * **tools.c** — 
    * **tools.h** —
- **_template.c** — 
- **README.md** — this documentation.
- Tasks

### Using
#### Windows:
...
#### Linux:
0. `git` and `clang` should be installed
1. Clone the repo:
```
git clone ... && cd Stack-Pack
```
2. Compile one of the tasks connecting files **tools.c** and **stack.c**:
```
clang -g <task> tools.c stack.c -o <output>
```
3. Run the resulting executable:
```
./<output>
```