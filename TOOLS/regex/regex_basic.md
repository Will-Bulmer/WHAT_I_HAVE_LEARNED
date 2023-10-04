# LEARNING REGEX

## Learning the Basics

### 1. Intro
Short for `Regular Expression`. Helps to match, find or manage text.

### 2. What is Regular Expressions `Regex`
Regular Expressions are a string of characters that express a `search pattern`.

**Search Pattern:** Template used to identify specific types of data. Ie. For an email, it is @ symbol surrounded by characters on each side, followed by a period and a domain suffix.

*Example: Finding files with `pdf` extension*
`regex`
```regex
^\w+\.pdf$
```

### 3. Dot `.`: Any Character
The period `.` allows selecting any character (special and spaces)

### 4. Character Sets `[abc]`
One of the characters in a word can be various characters. Typing aeiou into [] `selects all`
`text`
bar ber bir bor bur
`regex`
```regex
b[aeiou]r
```

### 5. Negated Character Sets `[^abc]`
Select all but b`e`r and b`o`r.
`text`
bar ber bir bor bur

`regex`
```regex
b[^eo]
```
### 6. Letter Range `[a-z]`
Case sensitive. Boundaries included.

### 7. Number Range `[0-9]`
Boundaries included.

### 8. Repetitions
Specify how many times a character will be repeated.
These are `+`, `*`, `?`

#### 8a. Asterisk `*`
Put `*` after a character to say it may not match at all or can match many times. Ie. To select all below...
`text`
br ber beer
`regex`
```regex
be*r
```

#### 8b. Plus Sign `+`
Character can occur one or more times. To select `ber` and `beer`
`tex`
br ber beer
`regex`
```regex
[be+r]
```

#### 8c. Question Mark `?`
Character is optional. To select all below...
`text`
color, colour
`regex`
```regex
colou?r
```
#### 8d. Curly Braces `{n}` or `{n,}` or `{x,y}`
Certain number of occurances. Or certain number of occurrences after a character. Comma indicates `or more`.
`text`
ber beer beeer beeeer
`regex`
```regex
be{2}r   // Exactly 2
be{3,}r  // 3 or more
be{1,3}r // Between 1 and 3
```
### 9. Grouping

#### 9a. Parantheses `()`: Grouping
Close an expression and use groups to reference or enforce rules
`text`
ha-ha,`haa`-`haa`
`regex`
```regex
(haa)
```

#### 9b. Referencing a Group
`ha`and `haa` are grouped. Use `\1` to avoid rewriting. 1 is the `group order`.
`text`
`ha-ha,haa-haa`
`regex`
```regex
(ha)-\1,(haa)-\2
```

#### 9c. Paretheses `(?:)`: Non-capturing Grouping
Group an expression and ensure it is not captured by references. Non-capturing groups are not remembered.
`text`
`ha-ha,haa-haa`
`regex`
```regex
(?:ha)-ha,(haa)-\1 // ha is the first group (non-capturing)
```

### 10. Pipe Character `|`
Different to characters sets (character level). Alternatives operate at the expression level.
`text`
`cat rat dog`
`regex`
```regex
(c|r)at|dog
```

### 11. Escape Character `\`
Before selecting characters, need an escape character
`text`
(`*`) Asterisk`.`
`regex`
```regex
(\*|\.)
```

### 12. Caret Sign `^`: Selecting by Line Start
Numbers at the start of a line is `^[0-9]`

### 13. Dollar Sign `$`: Selecting by End of Line
Select html at end is using `html$`

### 14. Word Character `\w`: Letter, Number and Underscore
Used to find word characters (no specials)

### 15. Except Word Character `\W`
Find specials and spaces.

### 16. Number Character `\d` and except `\D`

### 17. Space Character `\s` and except `\S`

### 18. Lookarounds
Want a phrase that comes before another phrase, need a `lookaround`

#### 18a. Positive Lookahead: `(?=)`
Having values after them.
`text`
Date: 4 Aug `3` PM
`regex`
```regex
\d+(?=PM)
```

#### 18b. Negative Lookahead: `(?=)`
Not having values after them.
`text`
Date: 4 Aug `3` PM
`regex`
```regex
\d+(?!PM)
```

#### 18c. Positive Lookbehind: `(?<=)`
Things that are prefixed.
`text`
Product Code: 1064 Price: $`5`
`regex`
```regex
\d+(?<=\$)
(?<=\$)\d+
```

### 19. Flags
Also called `modifiers` change the output of an expression. Determines whether typed expression treats text as separate lines, is case sensitive, or finds all matches.

#### 19a. Global Flag `/g`
Selects all matches. If not used, will only select first match.
`text`
`domain.com, test.com, site.com`
`regex`
```regex
\w+\.com /g
```

#### 19b. Multiline Flag `/m`
Regex sees all text as one line. Expression to identify patterns at the end of each line works separately for each line.
`text`
`domain.com`
`test.com`
`site.com`
`regex`
```regex
\w+\.com$ /gm
```

#### 19c. Case-insensitive Flag `/i`
To remove case insensitvity. `/gmi`

#### 20a. Greedy Matching
Does this by default. Match as much as they can.
To match as many expressions as possible until an `r`. So for abcdrer, it will consume as much of the string as possible. abcdrer is result instead of abcdr
`text`
`ber beer beeer beeeer`
`regex`
```regex
.*r
```

#### 20b. Lazy Matching
Stops at the first matching.
`text`
`ber` beer beeer beeeer
`regex`
```regex
.*?r
```
