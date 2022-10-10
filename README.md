# Design_patterns_chain_of_responsibility

Problem:
The application performs validation of candidates. Adding new requirements violates open/closed principle.

Solution:

Chain of responsibility - a behavioral design pattern that lets you pass a request along chain of handlers.
Upon receiving a request each handler deceides either to process it or to pass the request to next handler. 
Checks must be performed sequentially.
