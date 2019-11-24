# 다이나믹 프로그래밍

백준 온라인 저지에서 분류별 알고리즘 풀기-> 다이나믹 프로그래밍 문제를 푼다. DP는 많이 나오는 유형이므로 꾸준히 풀면서 연습한다.

DP문제를 접근할 때는 다음의 사항을 고려해야 한다.

1. DP를 어떻게 정의할 것인가?
   - 항상 N번째 DP배열에 정답이 저장되어 있는것은 아니다. 정답을 구하기 위해 원하는 값을 저장(메모이제이션)하는 배열이다. 따라서 먼저 DP배열에 어떤값을 저장해야 그 값을 이용해서 답을 구할 수 있는지를 생각해봐야 한다.

2. DP배열의 초기화
   - 최솟값을 구하고 싶은데 DP값을 전역변수로 선언만한다면 어떤 값을 출력해도 0을 출력할 것이다. 이런실수는 생각보다 흔하게 볼 수 있다. (~~그게바로 접니다.~~) DP는 처음 저장된 값에 따라 값을 메모이제이션하면서 연쇄적으로 값을 저장하는 배열이다. 따라서 처음 값의 설정을 제대로 해주어야 원하는 값이 나온다.

## 문제 List

- ### [BOJ 10844 쉬운 계단 수](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%2010844%20쉬운%20계단%20수.md)

- ### [BOJ 2163 초콜릿 자르기](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%202163%20초콜릿%20자르기.md)

- ### [BOJ 9461 파도반 수열](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%209461%20파도반%20수열.md)

- ### [BOJ 14501 퇴사 ★](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%2014501%20퇴사.md)

- ### [BOJ 1010 다리 놓기 ★★](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%201010%20다리%20놓기.md)

- ### [BOJ 9465 스티커](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%209465%20스티커.md)

- ### [BOJ 11057 오르막 수](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%2011057%20오르막%20수.md)

- ### [BOJ 2167 배열의 합](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%202167%20배열의%20합.md)

- ### [BOJ 2294 동전 2](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%202294%20동전%202.md)

- ### [BOJ 1699 제곱수의 합](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%201699%20제곱수의%20합.md)

- ### [BOJ  11048 이동하기](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%2011048%20이동하기.md)

- ### [BOJ  11055 가장 큰 증가 부분 수열](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%2011055%20가장%20큰%20증가%20부분%20수열.md)

- ### [BOJ  2133 타일채우기 ★](https://github.com/jungtaeyong/alstudy2/blob/ty/다이나믹%20프로그래밍/baekjoon%202133%20타일채우기.md)



