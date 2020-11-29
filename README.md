# usdf-zsdf-dialogue-generator

A dialogue generator using both formats, [USDF](https://github.com/rheit/zdoom/blob/master/specs/usdf.txt) and [ZSDF](https://github.com/coelckers/gzdoom/blob/master/specs/usdf_zdoom.txt).

## v1.0 [RELEASED]
- Includes the dialogue generator for the USDF format _only_.
### v1.1 [RELEASED]
- Fixing IDENTIFIER bug
- Changing baseTag generation structure

## v2.0
Currently **WIP**
- Includes generators for both dialogue types.

#### Ideas
- [ ] CLI shell-like behaviour
- [ ] For the UI, use [ncurses](https://en.wikipedia.org/wiki/Ncurses) instead of raw C++ CLI
- [ ] Create an REST API using [Pistache](http://pistache.io/) (perha:b:s could use ncurses to manage the server), to be consumed by some webapp (React? Angular?)

#### TO-DO
- [x] Fix IDENTIFIER appearing before curly brackets.
