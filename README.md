# clck
A minimal clock utility which is designed to look pretty in your Linux or Mac terminal. It is highly customizable through the [config.h](https://github.com/Flederossi/clck/blob/main/src/include/config.h) file which lets you change the parameters of font, color, time format as well as size and offset (to cover a few) of your clock. You can use it as temporary time indicator or even your main system clock in a tiling window manager for example.

![Alt Text](https://github.com/Flederossi/clck/blob/main/assets/screen-1.png)

*Note: clck currently supports only macOS and Linux, but a Windows port may be added in the future*

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

To customize clck you can change the parameters of the [config.h](https://github.com/Flederossi/clck/blob/main/src/include/config.h) file to your needs and then recompile the project. Now your changes should be applied. There are comments on each customizable parameter in the configuration file which should explain the functionality of each specific value.

*Note: The following examples are just ones with some tiny changes. You can customize clck in the way you want. It even supports more detailed fonts (by specifiyng the CHAR_W and CHAR_H parameter) as well as the usage of any unicode character and hex color so that you can go crazy with your custom designs.*

### Examples
> - Different font, color, time format and space size to default configuration:
> ![Alt Text](https://github.com/Flederossi/clck/blob/main/assets/screen-2.png)

> - Different color, pixel character and space size to default configuration:
> ![Alt Text](https://github.com/Flederossi/clck/blob/main/assets/screen-3.png)
