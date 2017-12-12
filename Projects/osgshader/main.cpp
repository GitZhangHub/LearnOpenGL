#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osg/Shape>
#include <osg/ShapeDrawable>
#include <osg/MatrixTransform>
#include <osg/Texture2D>

static char * vertexShader= {
        "#version 430 \n"
        "layout (location=0) in vec3 VertexPosition;\n"
        "layout (location=1) in vec2 TexCorrd;\n"
        "uniform mat4 MVP;"
        "out vec2 Corrd;\n"
        "void main()\n"
        "{\n"
        "   Corrd = TexCorrd;"
        "   gl_Position = MVP * vec4(VertexPosition,1.0);\n"
        "}\n"
};

static char * fragShader ={
        "#version 430 \n"
        "uniform sampler2D sampler2d_0;\n"
        "uniform sampler2D sampler2d_1;\n"
        "layout (location=0) out vec4 FragColor;\n"
        "in vec2 Corrd;\n"
        "void main() {\n"
        "   vec4 tmpColor = texture(sampler2d_0, Corrd);"
        "   if(Corrd[1] > 0.5 ) \n"
        "		   tmpColor = texture(sampler2d_1, Corrd); \n"
        "   FragColor = tmpColor ;\n"
        "}\n"
};

class MVPCallback: public osg::Uniform::Callback
{
public:
        MVPCallback(osg::Camera * camera):mCamera(camera){
        }
        virtual void operator()( osg::Uniform* uniform, osg::NodeVisitor* nv){
                osg::Matrix modelView = mCamera->getViewMatrix();
                osg::Matrix projectM = mCamera->getProjectionMatrix();
                uniform->set(modelView * projectM);
        }

private:
        osg::Camera * mCamera;
};

osg::Node * createNode()
{
        osg::Geode * geode = new osg::Geode;

        osg::Geometry * gm = new osg::Geometry;

        osg::Vec3Array * vertexArray = new osg::Vec3Array;
        vertexArray->push_back(osg::Vec3(0,0,0));
        vertexArray->push_back(osg::Vec3(1,0,0));
        vertexArray->push_back(osg::Vec3(1,0,1));
        vertexArray->push_back(osg::Vec3(0,0,1));
        gm->setVertexArray(vertexArray);

        osg::Vec3Array * normalArray = new osg::Vec3Array;
        normalArray->push_back(osg::Vec3(0,-1,0));
        gm->setNormalArray(normalArray);
        gm->setNormalBinding(osg::Geometry::BIND_OVERALL);


        osg::Vec2Array* texcoords = new osg::Vec2Array(4);
        (*texcoords)[0].set(0.0f,0.0f);
        (*texcoords)[1].set(1.0f,0.0f);
        (*texcoords)[2].set(1.0f,1.0f);
        (*texcoords)[3].set(0.0f,1.0f);
        gm->setTexCoordArray(0,texcoords);


        gm->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS,0,vertexArray->size()));
        geode->addDrawable(gm);

        osg::StateSet* stateset = gm->getOrCreateStateSet();


        osg::Texture2D * texture0 = new osg::Texture2D;
        texture0->setDataVariance(osg::Object::DYNAMIC); // protect from being optimized away as static state.
        texture0->setImage(osgDB::readImageFile("/home/apple/workspace/LearnOpenGL/src/image/wall.jpg"));
        stateset->setTextureAttributeAndModes(0,texture0,osg::StateAttribute::ON);


        osg::Texture2D * texture1 = new osg::Texture2D;
        texture1->setDataVariance(osg::Object::DYNAMIC); // protect from being optimized away as static state.
        texture1->setImage(osgDB::readImageFile("/home/apple/workspace/LearnOpenGL/src/image/map.jpg"));
        stateset->setTextureAttributeAndModes(1,texture1,osg::StateAttribute::ON);

        gm->setVertexAttribArray(0,vertexArray);
        gm->setVertexAttribBinding(0, osg::Geometry::BIND_PER_VERTEX);

        gm->setVertexAttribArray(1,texcoords);
        gm->setVertexAttribBinding(1, osg::Geometry::BIND_PER_VERTEX);

        return geode;
}
int main()
{
        osg::ref_ptr<osgViewer::Viewer> viewer  = new osgViewer::Viewer;


        osg::Group * root = new osg::Group;

        osg::Node * node = createNode();
        root->addChild(node);

        osg::StateSet * ss = node->getOrCreateStateSet();
        osg::Program * program = new osg::Program;
        program->addBindFragDataLocation("VertexPosition",0);
        program->addBindFragDataLocation("TexCorrd",1);

        osg::Shader * vS = new osg::Shader(osg::Shader::FRAGMENT,fragShader);
        osg::Shader * fS = new osg::Shader(osg::Shader::VERTEX,vertexShader);
        program->addShader(vS);
        program->addShader(fS);
        ss->setAttributeAndModes(program,osg::StateAttribute::ON);


        osg::Uniform* MVPUniform = new osg::Uniform( "MVP",osg::Matrix());
        MVPUniform->setUpdateCallback(new MVPCallback(viewer->getCamera()));
        ss->addUniform(MVPUniform);
        osg::Uniform* sample0 = new osg::Uniform("sampler2d_0",0);
        ss->addUniform(sample0);

        osg::Uniform* sample1 = new osg::Uniform("sampler2d_1",1);
        ss->addUniform(sample1);

        viewer->setSceneData(root);
        viewer->setUpViewInWindow(35, 35, 1024, 800);


        return viewer->run();
}
