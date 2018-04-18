# Excersises for design patterns in modern c++ [course](https://www.udemy.com/patterns-cplusplus/).

### [SOLID](https://en.wikipedia.org/wiki/SOLID_(object-oriented_design))
 
### Builder
- A separate component for building an object, can help avoiding huge constructors
- Can be created by constructor or by returning it via a static function from the class that is being build
- **Fluent builder** returns reference/pointer to self to be able to use in chain
- Facets enable using several builders to work on the same object by using a common base class

### Factory
- Responsible for the wholesale object creation, where Builder provides piecewise creation
- **Factory method** - use a static member method(instead of a constructor) to create an object
- **Factory** - separate component with factory methods, often done as inner class(**Inner Factory**)
- **Abstract Factory**(*Factory Family*) - group several Factories that share an interface and use the abstract version to create objects, not common these days.