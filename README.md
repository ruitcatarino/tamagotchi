# Tamagotchi
[![License: MIT](https://img.shields.io/badge/license-MIT-blue.svg)](https://spdx.org/licenses/MIT.html)

<p align="center">
  <img src="https://github.com/ruitcatarino/tamagotchi/blob/master/Tamagotchi.png?raw=true" alt="Tamagotchi start example."/>
</p>

## Overview
Tamagotchi is a simple virtual pet program developed in C. It enables users to interact with a digital pet, offering actions such as feeding, playing, and monitoring its well-being. The simulation is threaded and utilizes the `SIMULATION_SPEED` constant, representing each year in seconds.

## Installation

### Clone the repository
```bash
git clone https://github.com/ruitcatarino/tamagotchi
cd tamagotchi
```

### Build from source code and run it
``` bash
gcc tamagotchi.c -o tamagotchi -pthread
./tamagotchi
```

## Contributing

Feel free to submit a [pull request](https://github.com/ruitcatarino/tamagotchi/pull/new/main) or an [issue](https://github.com/ruitcatarino/tamagotchi/issues/new)!

## License

This project is open-source and available under the [MIT License](LICENSE). You are free to use, modify, and distribute it in accordance with the license terms.
