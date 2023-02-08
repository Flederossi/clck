# clck
A minimal designed clock to make your Linux or Mac terminal look pretty. It is highly customizable through the [config.h](https://github.com/Flederossi/clck/blob/main/src/include/config.h) file which lets you change font, color, time format as well as size and offset of your clock. You can use it as temporary time indicator or your main system clock in a tiling window manager.

## Installation
### Compile
> There are three ways to compile the project:

- Use make:
```
make build
```

- Use [fare](https://github.com/Flederossi/fare/):
```
fare build
```

- Use plain gcc:
```
gcc src/main.c -o bin/clck -I src/include/
```
---
### Run
> To run clck after compilation you can use:
```
./bin/clck
```
> *Note: If you want to run clck everywhere on your system you should add the binary to your PATH. Otherwise you have to specify the path to the binary everytime you want to use it from somewhere else or another program.*

## Customization
To customize clck you can change the parameters of the [config.h](https://github.com/Flederossi/clck/blob/main/src/include/config.h) file to your needs and then recompile the project. Now your changes should be applied. There are comments on each customizable parameter in the configuration file.
