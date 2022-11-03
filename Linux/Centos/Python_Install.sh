yum install gcc openssl-devel bzip2-devel libffi-devel -y
yum -y install wget
wget https://www.python.org/ftp/python/3.9.5/Python-3.9.5.tgz
tar -xvf Python-3.9.5.tgz
cd Python-3.9.5
./configure --enable-optimizations
make altinstall
vi /root/.bashrc
#enter this sentence in: alias python="/usr/local/bin/python3.9"
#Next: source /root/.bashrc
yum -y install python3-pip