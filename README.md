# cli-assistant
A CLI-based personal assistant

Keep in mind that the software is under development and it's in its alpha stage, and a some features will change over time.

How to use cli-assistant
------------------------

1. Clone this repository
2. Navigate to the files of this repository
3. Run `make` to compile the software
4. Run `./assistant` to run the software

How to use cli-assistant
------------------------

The cli-assistant is supposed to work in a similar way programs like Apple's Siri and Microsoft's Cortana (and other similar applications) work, by typing a question, and according to the question, the assistant will show what you asked for.

`cli-assistant` works by detecting a keyword in the input of the user. And various information will appear, according to the detected keyword.

For the voice output, the `espeak-ng` package is required.

Keywords
--------

There are 4 available keywords in the software

1. `weather` - It shows the weather in your area.
2. `time` - It shows the time.
3. `date` - It shows the date.
4. `website` - It launches your browser with a requested website.

Flags
-----

There are two flags in the program's code that can be changed (their values can be either `1` or `0`).

1. `VOICE` - It toggles the voice output.
2. `DEV` - It toggles the developer mode.

The values can also be disabled when compiling by running `make no-voice` or `make no-dev`.
