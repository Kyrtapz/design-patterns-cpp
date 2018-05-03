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

### Prototype
- Partially or fully constructed object that is going to be copied(cloned) and used(modified)
- Important part is performing deep copy of the objects, serializers can be useful

### Singleton
- A component which is instantiated only once
- Hard to unit-test when used in a different component, it can be resolved with Dependency Injection
- Boost DI can be used to create a singleton using Lifetime
- **Monostone** - appears as a normal component but is based on static variables. Obviously dangerous, bad idea to use in most cases

### Adapter
- Getting the interface you want from the interface you have (Wall power adapter is a real world example)
- Adapts existing interface to conform to the new one
- **Caching adapter** - cashes temporary data, good idea to use when the data is generated several times with the same input

### Bridge
- Connects components through abstractions
- Prevents ***Cartesian product*** complexity explosion(Example: ThreadSched can be preemptive/Cooperative and run on Linux/Windows which equals to 4 different components)
- Decouples an interface from an implementation
- **Pimpl idiom** - Implementation of class methods are moved to another class(pointer to the implementation is stored in the class and then used in the methods instead of the actual logic). Hides implementation details. Not used so often nowdays.

### Composite
- Treat individual and aggregate objects in the same way
- **Composite** - A mechanism for treating individual(scalar) objects and compositions of object in the same way 
- [CRTP - Curiously recurring template pattern](https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern)
- Array-Backed properties - Array indexed by enum that makes it easier to work on aggregated properties

### Decorator
- Adding behaviour without altering the class itself(add functionality to already existing element without modifying it)
- Add a wrapper class that keeps the reference of the element or derive from it
- **Dynamic decorator** - use base class element as a reference, it is dynamic since it is created at runtime. It is possible do decorate a decorator.
- **Static decorator** - Derive from the decorated class, better to use when it is known what specific class we are going to decorate. Defined at compile time.
- **Function decorator** - decorate a function

### Facade
- Expose several components through a single interface(example: House that has electricity, plumbing, etc.)
- Build a simpler API that manages several classes to achieve a specific scenario
- Expose underlying components to be used by power users


### Flyweight
- Avoid redundancy when storing data
- Space optimization technique that allows for using less memory by storing externally the data that is associated with similiar objects
- Boost.Flyweight is a valid solution for most use cases(example: flyweight`<string>`)

### Proxy
- An interface for accessing a particular resource with the same APIs that underlying resource presents(Same interface, different behaviour)
- A class that functions as an interface to a particular resource. That resource may be remote, expensive to construct, or may require logging or some other added functionality
- **Smart pointer** is an example of proxy - can be used as a normal pointer but does more than a plain pointer
- **Property** is another example of a proxy, hide a value behind getter and setter (overloading assignment and get operator)
- **Virtual proxy** - can be used for lazy loading, doesn't do things when called but later when they are needed. For instance opens a file not when open was called but when read from file was.
- **Communication proxy** - caller doesn't know if it calls a local resource or remote one
- There is a lot of different proxy types that can be used
- **Proxy vs Decorator** - Proxy provides identical interface while decorator provides an enhanced interface
- **Proxy vs Decorator** - Decorator typically aggregates the underlying object(reference/inheritance) while can just mimic the APIs
- **Proxy vs Decorator** - Proxy might not even create any object

### Chain of responsibility
- A chain of components who all get a chance to process a command or a query, optionally having default processing implementation and an ability to terminate the processing chain
- **Single linked list** - not used these days, create events using single linked lists and call next handler when invoking yours
- **Broker chain** - Use centralized list(boost signal is useful here) instead of chaining

### Command
- Wrap a command with an object to be able to record and reverse actions
- Encapsulate all details of an operation in a separate object
- **Composite command** - Use Composite pattern to execute several commands at once(example: a Macro in Microsoft office macros)
- **Query** - in terms of a design pattern meaning it is covered by Command design pattern. Query is typically not modifying the data while the command is. Command Query Separation (CQS)

