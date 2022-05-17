# apt Error
<p></p>

## 1. apt-get install lock error
오류 내용: <br>
E: Could not get lock /var/lib/dpkg/lock’
<br><br>
해결 방안: <br>

```bash
#first
sudo killall apt apt-get

# second
sudo rm /var/lib/apt/lists/lock
sudo rm /var/cache/apt/archives/lock
sudo rm /var/lib/dpkg/lock*

sudo dpkg --configure -a && sudo apt update
```