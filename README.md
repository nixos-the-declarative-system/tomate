# tomate 🍅

A Pomodoro timer for the terminal. Three files, a Makefile,
nothing else.

```console
$ tomate 25
🍅  25:00 — working.
```

Without an argument, `tomate` starts a 25-minute session. When it
ends, the terminal rings and invites you to take a break.

## Building and installing

```console
$ make
$ make install PREFIX=~/.local
```

A C compiler and `make` are all you need. `PREFIX` defaults to
`/usr/local`.

## About this project

`tomate` is the example project of the book *NixOS: The Declarative
System*: it is the tool the book teaches you to package. It really
works, but without the book it is just one more small timer among
many.

The Pomodoro Technique was created by Francesco Cirillo.
Pomodoro® is a registered trademark of Francesco Cirillo; this project
is independent and is neither affiliated with nor endorsed by him.

## License

MIT — see [LICENSE](LICENSE).
