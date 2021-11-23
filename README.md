<img src="./img.png" alt="Lee">

# Lee-lang

An esoteric language inspired by brainfuck, COW, and well, Lee.

## Hello Lee!

```
wee Print "Hello Lee!" wee

lEE lEE lEE lEE lEE lEE lEE lEE 

lee 
    leE lEE lEE lEE lEE

    lee
        leE lEE lEE
        leE lEE lEE lEE
        leE lEE lEE lEE
        leE lEE
        Lee Lee Lee Lee lEe
    LEE
    leE lEE
    leE lEE
    leE lEe
    leE leE lEE

    lee
        Lee
    LEE

    Lee lEe
LEE


leE leE croissant
leE lEe lEe lEe croissant
lEE lEE lEE lEE lEE lEE lEE croissant croissant lEE lEE lEE croissant

leE leE croissant

Lee Lee Lee lEE lEE lEE lEE croissant

leE 
lEe lEe lEe lEe lEe lEe lEe lEe lEe lEe croissant croissant

leE leE lEE croissant
```

## Usage

Use `leepls` and pass the source file as a command line argument:

```bash
leepls <src.lee>
```

## Language Reference

Each separate *word* is read from the source and interpreted accordingly. Whitespaces aren't interpreted in any way and tokens can contain an innumerable number of whitespace characters in between them if desired.

### Comments

Anything after `wee` is interpreted as a comment and excluded until the next `wee` is encountered:

```
wee This is a comment wee

wee This is 
also 
a 
comment 
wee
```

### Memory Model

Each program has an associated 77,777 byte long memory wherein each byte can be modified using the operations the language provides. All the bytes are initialized with the value `0`.

### Operations

There are 8 keywords (or operations to be very specific) each with a designated task:

| Keyword | Behavior |
|:---:|:---:|
|`lee`|Jump past the corresponding `LEE` if the value in the currently pointed byte is `0` (falsy)|
|`LEE`|Go back to the corresponding `lee` if the value int he currently pointed byte is non-zero (truthy)|
|`lEe`|Decrease the value in the currently pointed byte by 1|
|`lEE`|Increase the value in the currently pointed byte by 1|
|`leE`|Move the byte pointer to the next byte|
|`Lee`|Move the byte pointer to the previous byte|
|`LEe`|Read an integer and store it in the currently pointed byte|
|`LeE`|Print the value in the currently pointed byte as an integer|
|`croissant`|Print the ASCII character corresponding to the value in the currently pointed byte|
|`baguette`|Read an ASCII character and store its corresponding decimal value in the currently pointed byte|
