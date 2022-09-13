# 13 . Vertex Array 设计

https://www.youtube.com/watch?v=rkxrw8dNrvI&list=PLlrATfBNZ98dC-V-N3m0Go4deliWHPFwT&index=32

本文讲解Vertex Aray 设计:

1. VAO相关的函数

1. Vertex Array 设计原理

   

## 1.VAO相关的函数

1、void glCreateVertexArrays(GLsizei n,GLuint arrays)；*
		返回n个未使用的对象名到数组arrays中，用作顶点数组对象。返回的对象名可以用来分配更多的缓存对象。当n为负数的时候，产生GL_INVALID-VALUE错误。

​		2、void glbindVertexArray(GLuint array)；
​				glCreateVertexArrays函数所生成的对象名，你可以看作是一个指针，我们可以分配内存并且用该指针来用引用该内存。当我们得到对象之后，可以将它绑定到OpenGL环境中以便使用它。
glbindVeretexArray()函数完成两相工作。如果array非0，并且是一个glCreateVertexArrays()函数生成的对象，那么会激活这个顶点数组对象并绑定到当前的环境中。如果array为0，那么OpenGL将不再使用之前绑定的顶点数组。
如果array不是glCreateVertexArrays()所产生的，或者它已经被glDeleteVertexArrays()函数所释放，那么将会产生一个GL_INVALID_OPERATION错误。

3、void glDeleteVertexArrays(GLsizei n,const GLuint arrays)；*
			删除n个在array中定义的顶点数组对象，删除后的所有名称可以再次用作顶点数组。如果绑定的顶点数组被删除，那么当前绑定的顶点数组对象被重设为0，并且不再存在一个当前对象。

4、GLboolean glIsVertexArray(GLuint array)；
判断array是否是一个glCreateVertexArrays()创建且没有被删除的顶点数组对象的名称。

## 2. Vertex Array 设计原理

整个数据设置&渲染流程：

![image-20220913170944460](https://raw.githubusercontent.com/DionysosLai/PicGoImage/main/20220913170954.png)

 因此，我们可以将整个VAO 设置都抽象化，即VertexArray 设计；

![image-20220913171227471](https://raw.githubusercontent.com/DionysosLai/PicGoImage/main/20220913171229.png)

大概代码如下：

```c++
	class VertexArray
	{
	public:
		virtual ~VertexArray() {};

		virtual void Bind() const = 0;
		virtual void UnBind() const = 0;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) = 0;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) = 0;

		virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const = 0;
		virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const = 0;

		static VertexArray* Create();
	};
```



