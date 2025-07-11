# 2TSort

## Name / about
> **T**o **S**tart - **T**o **S**ort

Symbolizes putting items to start in order to sort it.

Initials of this statement is `TSTS`, so it can be rewritten as `2×TS`.

And as final naming step, **`2TSort`** was made up.

## Algorithm
- Loop every element from start from finish
- If `next` element is **smaller** than `current` element
- **Rotate right** all items from start to `current + 1`
- - alternate explanation: 
- - put `current + 1` item to start and **right shift** all elements from `start` to `current`
- Then keep looping to end of array

>
- If change happened, do it again, but loop only till `last change index`

```
3 1 2		// desorted
1 3 2		// 1st trigger, 1 < 3, put 1 to start
2 1 3		// 2nd trigger, 2 < 3, put 2 to start
		// changes happened, let's loop one more time
1 2 3		// 3rd trigger, 1 < 2, put 1 to start
```

## Best usage
Because of sort's attribute of putting elements strictly to start,
best usage is if you know that array is as close to reversed as possible:
```
3 2 1		// reversed
2 3 1		// 1st trigger, 2 < 3, put 2 to start
1 2 3		// 2nd trigger, 1 < 3, put 1 to start
```

## Comparations
> all times are in ms

---

### 10 items to sort

| Algorithm     |   Random |  Ordered | Reversed | 
|---------------|----------|----------|----------|
| 2TSort        | 0.000883 |  5.3e-05 | 0.000169 |
| QuickSort     | 0.000233 | 0.000183 | 0.000403 |
| BubbleSort    | 0.000358 | 0.000156 | 0.000282 |
| InsertionSort | 0.000154 |  7.3e-05 | 0.000154 |
| SelectionSort |  0.00024 | 0.000129 | 0.000206 |

---

### 1000 items to sort

| Algorithm     |   Random |  Ordered | Reversed |
|---------------|----------|----------|----------|
| 2TSort        |  7.64065 | 0.040225 | 0.050484 |
| QuickSort     | 0.044443 | 0.278339 | 0.187085 |
| BubbleSort    |  2.41467 | 0.244861 |  2.47161 |
| InsertionSort | 0.103931 |  0.00072 | 0.149645 |
| SelectionSort | 0.199785 | 0.149708 | 0.161307 |

---

### 20 000 items to sort

| Algorithm     |   Random |  Ordered | Reversed |
|---------------|----------|----------|----------|
| 2TSort        |  24501.6 | 0.007066 |  30.2615 |
| QuickSort     |  0.81963 |  115.255 |   79.665 |
| BubbleSort    |  868.532 |   107.89 |   968.23 |
| InsertionSort |  33.6388 | 0.014181 |  85.3589 |
| SelectionSort |  69.8412 |  70.7724 |  75.7076 |

---

## How to run 

- ### 2TSort:
`make 2TSort` for creating executable

`./2TSort num` where `num` is `integer` of how many randomized numbers to sort

or `make run` or `make sort`, with optional attribute `SIZE=num` where 'num' is same as mentioned before
(so whole command can look like `make sort SIZE=1000000`)

- ### Comparation:

`make comp` for creating executable

`./comp num` where `num` is `integer` of how many randomized numbers to sort

or `make compare`, with optional attribute `SIZE=num` where 'num' is same as mentioned before
(so whole command can look like `make compare SIZE=1000000`)

Durations will be stored in `comp_out.txt`

---

> run all commands from project's `root` directory

> default `num` value is 1000

---


## How was created
In 2nd year of my high-school studies at [SSND](https://it-lyceum.tech/) we were learning C++.
Few lessons consisted of sorting algorithms.

We learned basic algorithms, such as bubble, quick or selection sort.

I wanted to create one too, so I thought, experimented and created few.
But as you can expect, in every one of them I met with statement "*It is ___ algorithm*" or "*It was already created*".

But then I came up with something I didn't see in any of them: put them to margin, not just swap or pick specific index.

So I put into work and created first working code.
I ran it with ~5 elements..... and it worked!!

Jupíí :)

But then I changed enlarged array size and it took waaaaaaaaay too long.

Like soooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo long, that I stated that it took `while(true)` to sort it.

Yet I was so happy with it that I immediately sent it to my teacher and friends.
But I continued on upgrading it, and noticed that when I detected trigger (`current + 1` is smaller than `current`), I put that item to start, but then started looping from start again.

So I just removed `i = 0`, and magic happened :)

It was way quicker.
But still not as quick as others.

I showed it to my friend [Damko](https://github.com/Damko757), and he just removed `print()` from `for-loop`.

And suddenly sorting times acceptably dropped :)

Last optimalisation I wanted for few years is to don't loop whole array every time, but loop just whats needed.
11.7.25 I implemented it :)

![2TSort logo](2TSort.png)
