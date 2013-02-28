using UnityEngine;
using System.Collections;

public class BallCatcher : MonoBehaviour {

	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		if (transform.position.y < -10f)
			transform.position = new Vector3(0f, 25f, 0f);
	}
}
