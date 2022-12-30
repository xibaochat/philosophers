<h1 align="center">
   <b font size="15" face="arial" ><br><br>philosophers</font></b></h1>
   <p align="center">
     
   <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/7/7b/An_illustration_of_the_dining_philosophers_problem.png/220px-An_illustration_of_the_dining_philosophers_problem.png">

   <p align="center">
   The basics of multi-threading, mutex and semaphores, through <a href="https://en.wikipedia.org/wiki/Dining_philosophers_problem">the dining philosophers problem</a>.</br>

  This project is a training to multi-threads/multi-process programming with the use of mutex and semaphore.
It contains 3 different programs simulating a twist of the famous Dining Philosophers problem, all with the same basic rules.
This project is also a good lesson in C optimization as we need to save every bit of CPU usage we can to ensure the survival of our philosophers.
</p>
 <p align="center">
  <img src="https://img.shields.io/badge/c-007ACC?style=for-the-badge&logo=c&logoColor=white">

  <table  align="center">
<td>
 <b face="arial" >final mark<br><br></font></b></p>
 <img src="https://github.com/xibaochat/philosophers/blob/master/final_mark.png">
 

</td>

<td>

| interest                     | number of team          | difficulty                      |
| ---------------------------- | ----------              | ----------                      |
|    :star::star::star::star: | :cat: |  :star::star::star: |

</td>
</tr>
</table>
<p>
philo_one: multi-threads and use of mutex<br>
philo_two: multi-threads and use of semaphore<br>
philo_three: multi-processes and use of semaphore<br>
</p>
## Installation

In the root of each sub repo, type:

```bash
make
```

## Usage

Once the binary is compiled, type:
```python
./[binary] #_of_philosophers time_to_die time_to_eat time_to_sleep [#_times_each_philosopher_must_eat]
```
![gif](https://github.com/xibaochat/philosophers/blob/master/philo.gif)


