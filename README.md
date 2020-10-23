# usdf-zsdf-dialogue-generator

A dialogue generator using both formats, [USDF](https://github.com/rheit/zdoom/blob/master/specs/usdf.txt) and [ZSDF](https://github.com/coelckers/gzdoom/blob/master/specs/usdf_zdoom.txt).

## v1.0.0

- [x] Generate a dialogue (based on mocked data)
    - [x] Fix "IFITEM" tag to create multiple
- [x] Receive user input, and generate a dialogue from it
    - [ ] Fix bugs related to it (WIP)
- [ ] Create the same project for the ZSDF format

### Desirable stuff:
- [ ] CLI shell-like behaviour
- [ ] For the UI, use [ncurses](https://en.wikipedia.org/wiki/Ncurses) instead of raw C++ CLI
- [ ] Create an REST API using [Pistache](http://pistache.io/) (perha:b:s could use ncurses to manage the server), to be consumed by some webapp (React? Angular?)
