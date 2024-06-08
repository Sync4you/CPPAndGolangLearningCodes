package splitstringdemo

import (
	"reflect"
	"testing"
)

func TestSplit(t *testing.T) {
	/* ret := Split("babcbef", "b")
	want := []string{"", "a", "c", "ef"}
	if !reflect.DeepEqual(ret, want) {
		t.Errorf("want: %v, but got: %v", want, ret)
	} */
	type testCase struct {
		str  string
		sep  string
		want []string
	}
	testGroup := []testCase{
		{"babcbef", "b", []string{"", "a", "c", "ef"}},
		{"a:b:b:c", ":", []string{"a", "b", "b", "c"}},
		{"dawdwa", "w", []string{"da", "d", "a"}},
		//{"沙河有沙又有河", "有", []string{"沙河", "沙又", "河"}},
	}
	for _, tc := range testGroup {
		got := Split(tc.str, tc.sep)
		if !reflect.DeepEqual(got, tc.want) {
			t.Fatalf("want: %v, but got:%v\n", tc.want, got)
		}
	}
}

func BenchmarkSplit(b *testing.B) {
	for i := 0; i < b.N; i++ {
		Split("a:b:c", ":")
	}
}
