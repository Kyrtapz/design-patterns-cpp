# design-patterns-cpp
## Excersises for design patterns in modern c++ [course](https://www.udemy.com/patterns-cplusplus/).

###Builder
- A separate component for building an object, can help avoiding huge constructors
- Can be created by constructor or by returning it via a static function from the the that is being build
- Fluent builder returns reference/pointer to self to be able to use in chain
- Facets enable using several builders to work on the same object by using a common base class
