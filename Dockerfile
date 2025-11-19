FROM ubuntu:22.04

# Temel araçlar ve Qt/CMake kur
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    qt5-qmake \
    qtbase5-dev \
    qtbase5-dev-tools \
    qtchooser \
    git \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Kaynak dosyalarını kopyala
COPY . .

# GitHub reposunu clone et
RUN git clone https://github.com/kaya-berk/ExcelParser.git .

# CMake ile derleme (varsayılan)
RUN mkdir -p build && cd build && cmake .. && make

# Eğer QMake kullanacaksan, yukarıdaki RUN satırını şununla değiştirebilirsin:
# RUN qmake && make

CMD ["./build/ExcelParser"]
