# cldeparser
An extensible lexical, syntax parser for languages commons (Json parsing is included by default)

Introduction:

I needed a data-driven configuration mechanic for another project. So I chose Json format and it was how this parser came to live.

Scanner:
- Use direct coded technique
- Pre-supported token includes: < , > ( ) [ ] { } \ / + - * true false null : ; id string number integer .
- Tokenizer class supports states tables

Parsing & Sematic:
- Use top-down direct coded (Recursive-Descent) parsing technique
- Json parsing uses an ad-hoc sematic analysing technique (Json entities are analysed based on a pre-created token queue and an entity scope stack)
