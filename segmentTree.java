static class SegmentTree<A extends Comparable<A>>{
		ArrayList<Pair<A,Integer>> minTree = new ArrayList<>();
		ArrayList<Pair<A,Integer>> maxTree = new ArrayList<>();
		int size, treeSize;
		
		SegmentTree(int size){
			this.size = size;
			this.treeSize = size<<3;
			for(; minTree.size() < treeSize; ){
				this.minTree.add(null);
				this.maxTree.add(null);
			}
		}
	
		Pair<A,Integer> minPair(Pair<A,Integer> a,Pair<A,Integer> b){
			if(a == null) return b;
			if(b == null) return a;
			return min(a,b);
		}
	
		Pair<A,Integer> maxPair(Pair<A,Integer> a,Pair<A,Integer> b){
			if(a == null) return b;
			if(b == null) return a;
			return max(a,b);
		}
		
		void update(int index,A value,int leftIndex,int rightIndex,int treeIndex){
			if((index < leftIndex) || (index > rightIndex)) return;
			if(leftIndex == rightIndex){
				minTree.set(treeIndex,new Pair<>(value, leftIndex));
				maxTree.set(treeIndex,new Pair<>(value, leftIndex));
				return;
			}
			int middleIndex = leftIndex + rightIndex >> 1;
			update(index, value, leftIndex, middleIndex, treeIndex<<1);
			update(index, value, middleIndex+1, rightIndex, treeIndex<<1|1);
			minTree.set(treeIndex, minPair(minTree.get(treeIndex<<1),minTree.get(treeIndex<<1|1)));
			maxTree.set(treeIndex, maxPair(maxTree.get(treeIndex<<1),maxTree.get(treeIndex<<1|1)));
		}
		
		public void update(int index,A value){
			update(index,value,0,size-1,1);
		}
		
		Pair<A,Integer> minQuery(int start,int end,int leftIndex,int rightIndex,int treeIndex){
			if((end < leftIndex) || (rightIndex < start)) return null;
			if((start <= leftIndex) && (rightIndex <= end)) return minTree.get(treeIndex);
			int middleIndex = leftIndex + rightIndex >> 1;
			Pair<A,Integer> leftResult = minQuery(start, end, leftIndex, middleIndex, treeIndex<<1);
			Pair<A,Integer> rightResult = minQuery(start, end, middleIndex+1, rightIndex, treeIndex<<1|1);
			return minPair(leftResult,rightResult);
		}
		
		Pair<A,Integer> minQuery(int start,int end){
			return minQuery(start, end, 0, size-1, 1);
		}
		
		Pair<A,Integer> maxQuery(int start,int end,int leftIndex,int rightIndex,int treeIndex){
			if((end < leftIndex) || (rightIndex < start)) return null;
			if((start <= leftIndex) && (rightIndex <= end)) return maxTree.get(treeIndex);
			int middleIndex = leftIndex + rightIndex >> 1;
			Pair<A,Integer> leftResult = maxQuery(start, end, leftIndex, middleIndex, treeIndex<<1);
			Pair<A,Integer> rightResult = maxQuery(start, end, middleIndex+1, rightIndex, treeIndex<<1|1);
			return maxPair(leftResult,rightResult);
		}
		
		Pair<A,Integer> maxQuery(int start,int end){
			return maxQuery(start, end, 0, size-1, 1);
		}
}
