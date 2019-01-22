# Data Handling
Tips on how to format and parse data.

## Generating and Parson JSON
Try the [`JsonParserGeneratorRK`](https://build.particle.io/libs/JsonParserGeneratorRK/0.0.6/) library for sending or receiving JSON data.

There is also the [`JsonStreamingParser`](https://build.particle.io/libs/JsonStreamingParser/1.0.5/) library,
which might be useful if you need to extract data from a large JSON response.


## Avoid the `String` class and string concatenation
When possible, avoid using the `String` class or string concatenation (with
or without the class). The use of strings requires dynamic memory allocation,
which can fragment the available memory. Instead, try to use functions like
`snprintf()` with one large format string.


---
[<- Home](/particle-cookbook)
