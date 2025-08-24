# Stack Pack — deal with dynamic structuers easily!
This toolkit was created during the preparation for the programming exam. To speed up the solution of tasks from several exam tickets, I decided to separate the common I/O and stack functions from the unique ones for each specific task.

**It will be useful for you if you want to:**
- better understand dynamic structures and recursion 
- improve C skills — the package covers topics such as pointers, files, preprocessor etc.
- solve another ticket or lab work — focus on your task, the rest of code is already written!

## Should work in
- [x] Windows *(Visual Studio IDE)*
- [x] Linux *(Clang compiler)*

## Structure
- **lib** — shared code implementing stack and its methods
    - **stack.c**
    - **stack.h**
    * **tools.c**
    * **tools.h**
- **_template.c** — use this file to solve new tasks
- Task files

## Using
### Windows:
Not tested.

### Linux:
0. `git` and `clang` should be installed
1. Clone the repo:
```shell
git clone ... && cd Stack-Pack
```
2. Compile one of the tasks connecting files **tools.c** and **stack.c**:
```shell
clang -g <task> tools.c stack.c -o <output>
```
3. Run the resulting executable:
```
./<output>
```
