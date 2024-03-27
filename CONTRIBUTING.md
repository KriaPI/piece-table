### Code style
This project uses Google's code style. Use clang-tidy to format. 
### Code comments
Comments should use proper punctuation and capitalise the beginning of sentences. Avoid unnecessary detail when describing things. Doxygen is used for functions, classes and structs (or any other definition).
### Commit messages
A commit message should contain a title and if necessary a body. The title and body should be separated by one line. The title should generally 
follow the form `Category: short description`. A category should generally be `setup`, `feature`, `bugfix`, `refactor`, `documentation`, `test` or `other`. The category should be based on the main purpose of the commit. 

Past tense should be preferred. Capitalise the beginning of the title and beginning of sentences (as you would writting any other text). Do not capitalise the letter after `:`. Use proper punctuation.   
### Branch names
A branch should have a category followed by a description or issue number, separated by `/`.
#### Categories 
`feature` - For adding a new feature. This could be a function or a functionality. This could also be a tool used for developement (such as a formatting tool).

`refactor` - For rewritting code in order to improve readability, performance or maintainablity. 

`document` - For writing or editing documentation. Documentation includes any code comments or text documents that  

`bugfix` - For anything that fixes behaviour that is not expected or intended.  
    
`other` - For everything else.
### Description
A short description of the task to be done in the branch. Replace spaces with dashes (`-`). All characters should be in lower case, except for names. As a general guideline, try keeping the description short and concise. Short in this context is roughly 25 characters, but this is an arbitrary number and should only be used as a rough reference. 
### Issue number
If the branch is created to fix an issue, write `issue-n` where `n` is the issue number. 
### Examples
`feature/add-Clang-tidy`

`refactor/simplify-conditionals`

`document/function-add_two_numbers`

`bugfix/memory-leak-after-calling-method-x`

`bugfix/issue-42`

`other/setup-Meson-build`
