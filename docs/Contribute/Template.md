# Vector
> Brief explanation.

## Operations & time complexity

|  Methods  | RunningTime |
|:---------:|:-----------:|
| push_back(val) |     O(1)    |
|   pop()   |     O(1)    |
|  empty()  |     O(1)    |

:point_right:you can use [table generator](https://www.tablesgenerator.com/markdown_tables)  

## Implementation

```cpp
#include <cstido>
#include <iostream>

template<typename T>
class Vector { //use TitleCase for DataStructure implementation
    ---snip---
}

int main() {
    //few lines of code to test your implementation
    Vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(rand()%100);
    }
    sort(v.begin(), v.end())
        for (auto x: v) {
            cout << x << ' ';
        }
}
```
:point_right: keep your implementation is self-contained.

## Related Problems
1. title of easy problem :star: [:link:](https://codeforces.com/problemset/problem/1199/A)
2. Some hard problem :star::star::star::star: [:link:](https://codeforces.com)
3. Lily want a phone :star::star::star::star::star: [:link:](https://codeforces.com)


:point_right: add difficulty information(optional)

## Related Topics
[Stack](https://icpc.ninja)

## Analysis (Optional)
You can add some mathematical things here using [KaTex](https://katex.org/docs/supported.html)

as a block tag
$$
    T(N) = O(N*M)
$$

or as a inline tag $T(N) = O(N) $

### Contributers (Optional)
07.12.2019 :tada: [contributer1](https://github.com/jchrys)  
07.14.2019 :pencil2: typo correction [contributer2](https://github.com/jchrys)  
07.15.2019 :sparkles: add new section "Analysis" [contributer3](https://github.com/jchrys)   
07.18.2019 :bug: fix bugs in  "implementation" [contributer4](https://github.com/jchrys)   
07.19.2019 :zap: improved performance "implementation" [contributer5](https://github.com/jchrys)   
07.23.2019 :recycle: refactoring "implementation" [contributer6](https://github.com/jchrys)   
08.02.2019 :heavy_plus_sign: add related problems [contributer7](https://github.com/jchrys)
