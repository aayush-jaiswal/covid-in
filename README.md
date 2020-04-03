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

## Usage

* Get overall updates
```sh
$ covid-in
```

* Show help
```sh
$ covid-in -h
```

* Show statecodes
```sh
$ covid-in --statecodes
```

* Get stats of specific state or multiple states
```sh
$ covid-in -s [statecode]
```
OR 
```sh
$ covid-in -s [statecode seperated by comma]
```