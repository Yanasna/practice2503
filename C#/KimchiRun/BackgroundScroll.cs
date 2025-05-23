using UnityEngine;

public class NewMonoBehaviourScript : MonoBehaviour
{
    // Start is called once before the first execution of Update after the MonoBehaviour is created
        void Start()
    {
        
    }
    [Header("settings")]
    [Tooltip("How fast should the texture scroll?")]
    public float scrollSpeed; 
    [Header("Reference")]

    public MeshRenderer meshRenderer;

    // Update is called once per frame
    void Update()
    {
        meshRenderer.material.mainTextureOffset += new Vector2(scrollSpeed *Time.deltaTime, 0);
    }
}
