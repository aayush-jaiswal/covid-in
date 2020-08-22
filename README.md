# covid-in

A command line app to get covid-19 update.

## Installation

```sh
$ git clone https://github.com/aayush-jaiswal/covid-in.git
$ cd covid-in/
$ make
```

To install it in /usr/local/bin/ and use it globally run the following command
```sh
$ sudo make install
```

### Dependencies

[libcurl](https://curl.haxx.se/docs/install.html)

Install on Ubuntu based distro
```sh
$ sudo apt install libcurl4-openssl-dev
```

## Usage

* Get overall updates

![Example 1](./screenshots/ex1.png)

* Get updates of all states in tabular form

![Example 2](./screenshots/ex2.png)

* Get updates of a specific state

![Example 3](./screenshots/ex3.png)

* Show help
```sh
$ covid-in -h
```

* Get stats of number of samples tested
```sh
$ covid-in -t
```

* Show statecodes
```sh
$ covid-in --statecodes
```

* Get stats multiple states 
```sh
$ covid-in -s [statecode seperated by comma]
```

--- 

### TODOs

- [x] Add option to show tested data 
- [x] Show delta changes
- [x] Better output formatting
- [x] Add option to show data of all states in tabular form

### Data Source

https://www.covid19india.org/


### Libraries used

[json](https://nlohmann.github.io/json/)

[cxxopts](https://github.com/jarro2783/cxxopts)
