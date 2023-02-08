# clck
A minimal designed clock to make your Linux or Mac terminal look pretty. It is highly customizable through the config.h file which lets you change font, color as well as size and offset of your clock. You can use it as temporary time indicator or your main system clock.

## Installation
### Compile
> There are three ways to compile the project:
---
- Use Make:
```
make build
```
---
- Use Fare:
```
fare build
```
---
- Use plain gcc:
```
gcc src/main.c -o bin/clck -I src/include/
```
### Run
To run clck after compilation you can use:
```
./bin/clck
```

## Customization
To customize clck you can change the parameters of the config.h file in src/include/ to your needs and then recompile the project. Now your changes should be applied. There are comments on each customizable parameter in the configuration file.
