## Regex Practice Questions

### 1. Practice: Basic Matcher
Write the expression that will select the words `of` in the text.
`regex`
```regex
of
```

### 2. Practice: Any Character
Type the expression to select individual letters, numbers, spaces, and special characters in the text. The expression you type must match any character.
`regex`
```regex
.
```

### 3. Practice: Character Sets
Write the phrase that matches each word in the text. The only characters that change are the initials of the words.
`text`
`beer deer feer`
`regex`
```regex
[bdf]eer
```

### 4. Practice: Negated Characters Sets
Write down the expression that will match anything other than the words `beor` and `beur` in the text. Do this using the negated character set.
`text`
`bear` beor `beer` beur
`regex`
```regex
be[^ou]r
```

### 5. Practice: Letter Range
Write the expression that will select the letters from `g` to `k` in the text.
`g` and `k` letters should also be included in this range.
`text`
abcdef`ghijk`lmnopqrstuvwxyz
`regex`
```regex
[g-k]
```

### 6. Practice: Number Range
Type an expression to select numbers from `2` to `7` in the text.
`2` and `7` should also be included in this range.
`text`
`01234567`89
`regex`
```regex
[2-7]
```
### 7. Practice: Asterisk `*`
Use the asterisk `*` to write the expression that will select each word, suitable for the absence of the letter `e` in the text and the presence of one or more.
`text`
dp dep deep
`regex`
```regex
de*p // 0 or more times
```

### 8. Practice: Plus Sign `+`
Write the expression using the plus sign `+` to select words in which the letter `e` occurs one or more times in the text.
`text`
`dp dep deep`
`regex`
```regex
de+p // One or more times
```

### 9. Practice: Question Mark `?`
Write the expression indicating that the letter `n` is optional in the text, using the question mark `?`.
`text`
`a, an`
`regex`
```regex
an?
```
### 10. Practice: Curly Braces - 1
Curly braces to find number strings. Remember that the range `[0-9]` will match a single digit.
`text`
Release 10/9/2021
`regex`
```regex
[0-9]{4} // 2021
[0-9]{2,} // 10 and 2021
[0-9]{1,4} // 10, 9 and 2021
```

###

`text`

`regex`
```regex

```
