# 11/25/2026 - 4 days in to development

## Still puzzled on how to implement a passive system that would be modular so each passive for every character will fundamentally have the same underlying structure and systems for implementing.

### Order
### -Battle Context
-Session
 |
 V
-Put battle context in Session

### Skills, Ultimate should get a battle context struct
-The class abilities for each character, their only information outside is the battle context passed as a parameter
-Put battle context in skill and ultimate, and possibly even in basic atk because
some characters have empowered basic atks

### I think there will be a class will and there houses the listener that could:
- Listen for every action e.g., Skills, Ultimate, Basic
- I think.. listen for the passive

### Battle context just has data on what is there currently, the listener would also have battle context

Maybe implment the queue first?

## Trying to figure out the flow of the gameplay loop
For all intents and purposes no speed system for now to simplify


For the passive
