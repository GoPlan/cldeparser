# cldeparser

INTRODUCTION:

An extensible lexical, syntax parser for languages commons (Json parsing is included by default).


I needed a data-driven configuration mechanic for another project. So I chose Json format and it was how this parser came to live.


Scanner:
- Use direct coded technique
- Pre-supported token includes: < , > ( ) [ ] { } \ / + - * true false null : ; id string number integer .
- Tokenizer class supports states tables


Parsing & Sematic:
- Use top-down direct coded (Recursive-Descent) parsing technique
- Json parsing uses an ad-hoc sematic analysing technique (Json entities are analysed based on a pre-created token queue and an entity scope stack)


HOW TO USE:

CMake program can be used to generate build files for platforms (supported by CMake). 
When built with Unix Makefiles (make && make install), 
both static & shared libraries should be copied into your destination directory. 
While headers are copied into "include", a sub-folder at the destination.


WEBSITE: https://github.com/GoPlan/cldeparser


GIT LINK: https://github.com/GoPlan/cldeparser.git
