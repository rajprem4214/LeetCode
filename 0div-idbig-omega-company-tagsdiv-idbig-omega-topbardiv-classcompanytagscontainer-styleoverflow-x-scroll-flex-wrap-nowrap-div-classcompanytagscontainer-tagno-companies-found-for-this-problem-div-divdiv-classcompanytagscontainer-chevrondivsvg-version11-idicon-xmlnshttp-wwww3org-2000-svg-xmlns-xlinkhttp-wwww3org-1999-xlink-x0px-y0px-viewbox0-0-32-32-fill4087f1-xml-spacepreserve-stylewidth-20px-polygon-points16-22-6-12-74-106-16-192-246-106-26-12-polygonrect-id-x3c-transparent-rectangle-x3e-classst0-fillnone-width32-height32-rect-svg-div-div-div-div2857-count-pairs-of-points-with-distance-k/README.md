<h2><a href="https://leetcode.com/problems/count-pairs-of-points-with-distance-k/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2857. Count Pairs of Points With Distance k</a></h2><h3>Medium</h3><hr><div><p>You are given a <strong>2D</strong> integer array <code>coordinates</code> and an integer <code>k</code>, where <code>coordinates[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> are the coordinates of the <code>i<sup>th</sup></code> point in a 2D plane.</p>

<p>We define the <strong>distance</strong> between two points <code>(x<sub>1</sub>, y<sub>1</sub>)</code> and <code>(x<sub>2</sub>, y<sub>2</sub>)</code> as <code>(x1 XOR x2) + (y1 XOR y2)</code> where <code>XOR</code> is the bitwise <code>XOR</code> operation.</p>

<p>Return <em>the number of pairs </em><code>(i, j)</code><em> such that </em><code>i &lt; j</code><em> and the distance between points </em><code>i</code><em> and </em><code>j</code><em> is equal to </em><code>k</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> coordinates = [[1,2],[4,2],[1,3],[5,2]], k = 5
<strong>Output:</strong> 2
<strong>Explanation:</strong> We can choose the following pairs:
- (0,1): Because we have (1 XOR 4) + (2 XOR 2) = 5.
- (2,3): Because we have (1 XOR 5) + (3 XOR 2) = 5.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> coordinates = [[1,3],[1,3],[1,3],[1,3],[1,3]], k = 0
<strong>Output:</strong> 10
<strong>Explanation:</strong> Any two chosen pairs will have a distance of 0. There are 10 ways to choose two pairs.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= coordinates.length &lt;= 50000</code></li>
	<li><code>0 &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>6</sup></code></li>
	<li><code>0 &lt;= k &lt;= 100</code></li>
</ul>
</div>