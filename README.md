# Kicau

A Twitter-like application written in C, running on abstract data types implemented by hand.
Tugas Besar IF2110 Algoritma dan Struktur Data, Kelompok L.

## Build and run

```bash
make          # builds ./start.exe
./start.exe
```

Requires a C11 compiler and Make. `make clean` removes the build output.

**Commands must end with a semicolon.** The word machine treats `;` as its terminator, so
`LOGIN;` works and `LOGIN` will appear to hang. This trips up everyone on first contact.

Start by loading the sample data:

```
LOAD;
Configs
LOGIN;
```

`Configs/` holds a populated dataset — users, kicauan, threads, replies and drafts.
`TESKICAU/` and `LOL/` are smaller alternatives.

## What it does

Posting and a friend-filtered timeline, threads, nested replies, drafts with undo,
friend requests and a friend graph, user profiles, and save/load to config files.

## The ADTs

The point of the exercise was implementing the data structures rather than using any.
`ADT_Bawaan/` holds the course-provided primitives — boolean, character machine, word
machine, a 100×100 matrix, datetime and clock. Everything in `ADT_Tambahan/` was written
by the team:

| Structure | Where it's used |
| --- | --- |
| Left-child / right-sibling general tree | reply threads under a kicauan |
| Dynamic arrays | kicauan lists, thread lists |
| Linked stack | drafts, and the undo behind them |
| Linked list | thread segments |
| Edge-list graph | the friendship network |
| Circular-buffer priority queue | friend requests, keyed on mutual friend count |
| Static array | registered users |
| File character → line machine | parsing the config files |
| Recursive Levenshtein + anagram check | spell-checking mistyped commands |

`Driver/` holds a driver program per ADT for testing in isolation; `make driver_load` and
`make driver_kicauan` build and run two of them.

## Known issues

- Several headers declare functions as `void f();` and define them with parameters. That
  was ordinary C at the time but clang 15+ rejects it under `-Werror`, so the Makefile
  disables that one warning. The declarations should get real prototypes.
- `ADV()` in the character machine ignores the return value of `fscanf`, so reaching EOF
  without a terminating `;` spins forever instead of stopping.
- `deleteTree` frees a node without freeing its children, despite the comment promising a
  cascade. `wordToString` allocates and is never freed.
- `Command_Balasan.c` prints a not-found message on the success path.
- Build artifacts (`obj/`, `start.exe`, `driver_kicauan`) are committed to the repository
  and should be gitignored instead.
