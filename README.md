<div align = center>

# :speaker: Mini-Talk | 42 SP

![Norminette](https://github.com/RogerioLS/Mini_Talk-42sp/actions/workflows/norminette.yml/badge.svg)
![Build](https://github.com/RogerioLS/Mini_Talk-42sp/actions/workflows/build.yml/badge.svg)
![Static Badge](https://custom-icon-badges.demolab.com/badge/MINI_TALK-42-blue?logo=repo)
![42 São Paulo](https://custom-icon-badges.demolab.com/badge/42-SP-1E2952)
![License](https://custom-icon-badges.demolab.com/github/license/RogerioLS/Mini_Talk-42sp?logo=law&color=dark-green)
![Code size in bytes](https://custom-icon-badges.demolab.com/github/languages/code-size/RogerioLS/Mini_Talk-42sp?logo=file-code&color=dark-green)
![Top language](https://custom-icon-badges.demolab.com/github/languages/top/RogerioLS/Mini_Talk-42sp?color=dark-green)
![Last commit](https://custom-icon-badges.demolab.com/github/last-commit/RogerioLS/Mini_Talk-42sp?logo=history&color=dark-green)
![Repo size](https://custom-icon-badges.demolab.com/github/repo-size/RogerioLS/Mini_Talk-42sp?logo=database)
![Languages](https://custom-icon-badges.demolab.com/github/languages/count/RogerioLS/Mini_Talk-42sp?logo=command-palette&color=red)
![GitHub repo file count (file type)](https://custom-icon-badges.demolab.com/github/directory-file-count/RogerioLS/Mini_Talk-42sp%2Fsources?logo=file&label=files%20sources&color=8602b1)
![Discord](https://custom-icon-badges.demolab.com/discord/1114673462859006044?&logo=comments&label=testemunhas%20de%20vim&color=ffbe3a)
</div>

---

<div align = center>

![](https://game.42sp.org.br/static/assets/achievements/minitalkm.png)

</div>

### About

The purpose of this project is to code a small data exchange program using *UNIX signals*.

### Mandatory

- Produce `server` & `client` executables
- `client` must communicate a string passed as a parameter to `server` *(referenced by its process ID)* which then displays it
- Use `SIGUSR1` & `SIGUSR2` signals **ONLY**

### Bonus

- Add reception acknowledgement system
- Support Unicode characters

### Allowed Functions

- [`malloc`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`free`](https://man7.org/linux/man-pages/man3/free.3.html)
- [`write`](https://man7.org/linux/man-pages/man2/write.2.html)
- [`getpid`](https://man7.org/linux/man-pages/man2/getpid.2.html)
- [`signal`](https://man7.org/linux/man-pages/man2/signal.2.html)
- [`sigemptyset & sigaddset`](https://man7.org/linux/man-pages/man3/sigsetops.3.html)
- [`sigaction`](https://man7.org/linux/man-pages/man2/sigaction.2.html)
- [`pause`](https://man7.org/linux/man-pages/man2/pause.2.html)
- [`kill`](https://man7.org/linux/man-pages/man2/kill.2.html)
- [`sleep`](https://man7.org/linux/man-pages/man3/sleep.3.html)
- [`usleep`](https://man7.org/linux/man-pages/man3/usleep.3.html)
- [`exit`](https://man7.org/linux/man-pages/man3/exit.3.html)

## Compilation

### 1 - First things first, you need to clone this repository:

```python
git clone https://github.com/RogerioLS/Mini_Talk-42sp
```

### 2 - Go to Minitalk and run <b>make</b>

```python
cd Mini_Talk-42sp/
make
```

### 3 - Run server to get its PID and use it on client side to send the message you want. 

```python
./server
./client <server_PID> <message>
```

and that's basically it! :)