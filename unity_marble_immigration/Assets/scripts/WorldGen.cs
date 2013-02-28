using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class WorldGen : MonoBehaviour {
	
	public Transform[] woodPrefabs;
	public List<Transform> woods = new List<Transform>();
	public Light sunlight;
	
	public int gridSizeX = 20;
	public int gridSizeY = 20;
	
	public float heightScale = 10f;
	public float perlinResolution = 20f;
	
	bool animating = false;

	// Use this for initialization
	void Awake () {
		InstantiateGrid();
	}
	
	void Start () {
		AnimateToPerlinGrid();
	}
	
	// Update is called once per frame
	void Update () {
//		if (Input.GetKeyDown(KeyCode.R) )
//			AnimateToPerlinGrid();
	}
	
	void InstantiateGrid () {
		woods.Clear();
		for (int y=0; y<gridSizeY; y++) {
			for (int x=0; x<gridSizeX; x++) {
				Transform newWood = Instantiate(woodPrefabs[Random.Range(0, woodPrefabs.Length)], 
									new Vector3 (x, 0f, y), 
									Quaternion.Euler(new Vector3(0f, 90f * Random.Range(0, 4), 0f) ) ) as Transform;
				woods.Add(newWood);
			}
		}
	}
	
	void AnimateToPerlinGrid () {
		AnimateToPerlinGrid( Random.Range(0f, 100f) );
	}
	
	void AnimateToPerlinGrid (float seed) {
		if (animating)
			return;
		
		animating = true;
		
		Vector3[] woodScales = new Vector3[gridSizeX * gridSizeY];
		
		for (int y=0; y<gridSizeY; y++) {
			for (int x=0; x<gridSizeX; x++) {
				float perlin = Mathf.PerlinNoise(x/perlinResolution + seed, y/perlinResolution + seed);
				woodScales[x + (y * gridSizeX)] = new Vector3(1f, perlin * heightScale - (heightScale * .02f), 1f);
			}
		}
		
		StartCoroutine( AnimateGrid(woodScales, 3f) );
	}
	
	IEnumerator AnimateGrid (Vector3[] woodScales, float duration) {
		const int animateBatchSize = 4000;
		float t=0; // initialize timer
		
		// pull all old wood scales
		List<Vector3> oldWoodScales = new List<Vector3>();
		foreach (Transform wood in woods) {
			oldWoodScales.Add(wood.localScale);
			wood.collider.enabled = false;
		}
		float initialCamHeight = Camera.main.transform.position.y;
		
		float startTime = Time.time;
		
		while (t < 1f) {
			float frameLength = Time.time - startTime;
			startTime = Time.time;
			
			t += frameLength / duration;
			Camera.main.transform.position = new Vector3(Camera.main.transform.position.x, Mathf.Lerp(initialCamHeight, heightScale + 10f, t), Camera.main.transform.position.z);
			
			int counter = 0;
			for (int i=0; i<woodScales.Length; i++) {
				woods[i].localScale = Vector3.Lerp(oldWoodScales[i], woodScales[i], t);
				counter++;
				if (counter > animateBatchSize) {
					counter = 0;
					yield return 0;
				}
			}
			yield return 0;
		}
		
		foreach (Transform wood in woods) {
			wood.collider.enabled = true;
		}
		
		animating = false;
	}
	
	void OnGUI () {
		GUI.Label(new Rect(0f, 0f, 192f, 24f), "Bump Height (" + heightScale.ToString() + ")" );
		heightScale = GUI.HorizontalSlider(new Rect(192f, 0f, 256f, 16f), heightScale, 1f, 50f);
		
		GUI.Label(new Rect(0f, 24f, 192f, 24f), "Flatness (" + perlinResolution.ToString() + ")" );
		perlinResolution = GUI.HorizontalSlider(new Rect(192f, 24f, 256f, 16f), perlinResolution, 0.1f, 50f);
		
		GUI.enabled = animating ? false : true;
		
		if (GUI.Button(new Rect(0f, 48f, 128f, 32f), "Re-generate") )
			AnimateToPerlinGrid();
	}
}
